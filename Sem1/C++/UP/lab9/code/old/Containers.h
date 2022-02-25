#ifndef CLION_CLION_CONTAINERS_H_
#define CLION_CLION_CONTAINERS_H_

#include <initializer_list>
#include <vector>

//!BiDirectionalList
template<class T>
class BiDirectionalList {
 public:
  struct Node {
    T value;
    friend class BiDirectionalList;

   private:
    Node *prev;
    Node *next;
    explicit Node(T value_);
  };

  BiDirectionalList() : front(nullptr), back(nullptr) {}
  BiDirectionalList(std::initializer_list<T>) {}

  int Size() const;
  bool isEmpty();

  void PushFront(const T &value);
  void PushBack(const T &value);

  const Node *Front();
  const Node *Back();

  void PopFront();
  void PopBack();

  std::vector<T> ToVector();
  int Find(const T &value_);
  std::vector<T> FindAll(const T &value_);

  Node *operator[](int ind);

  void InsertBefore(Node *elem, const T &value_);
  void InsertAfter(Node *elem, const T &value_);

  void Erase(Node *elem);
  bool operator==(const BiDirectionalList &rhs) const;
  bool operator!=(const BiDirectionalList &rhs) const;

 private:
  Node *front;
  Node *back;
};

template<class T>
int BiDirectionalList<T>::Size() const {
  int size{1};
  if (back == nullptr) { return 0; }
  Node *tmp = back;
  while (tmp != front) {
    ++size;
    tmp = tmp->next;
  }

  return size;
}

template<class T>
bool BiDirectionalList<T>::isEmpty() {
  return (back == nullptr);
}

template<class T>
void BiDirectionalList<T>::PushFront(const T &value) {
  Node *tmp = new Node(value);
  if (front) {
    front->next = tmp;
    tmp->prev = front;
    front = tmp;
  } else {
    if (back == nullptr) { back = tmp; }
    front = tmp;
  }

}

template<class T>
void BiDirectionalList<T>::PushBack(const T &value) {
  Node *tmp = new Node(value);
  if (back) {
    back->prev = tmp;
    tmp->next = back;
    back = tmp;
  } else {
    if (front == nullptr) { front = tmp; }
    back = tmp;
  }
}

template<class T>
const typename BiDirectionalList<T>::Node *BiDirectionalList<T>::Front() {
  return front;
}

template<class T>
const typename BiDirectionalList<T>::Node *BiDirectionalList<T>::Back() {
  return back;
}

template<class T>
void BiDirectionalList<T>::PopFront() {
  if (isEmpty()) { return; }
  if (Size() == 1) {
    front = back = nullptr;
    delete front;
    return;
  }
  Node *tmp = front;
  front = front->prev;
  delete tmp;
}

template<class T>
void BiDirectionalList<T>::PopBack() {
  if (isEmpty()) { return; }
  if (Size() == 1) {
    delete back;
    return;
  }
  Node *tmp = back;
  back = back->next;
  delete tmp;
}

template<class T>
std::vector<T> BiDirectionalList<T>::ToVector() {
  std::vector<T> vector;
  Node *tmp = front;
  while (tmp) {
    vector.push_back(tmp->value);
    tmp = tmp->prev;
  }
  return vector;
}

template<class T>
int BiDirectionalList<T>::Find(const T &value_) {
  int ind{0};
  Node *tmp = front;
  while (tmp) {
    if (tmp->value == value_) { return ind; }
    ++ind;
    tmp = tmp->prev;
  }
  return -1;
}

template<class T>
std::vector<T> BiDirectionalList<T>::FindAll(const T &value_) {
  std::vector<T> vec{};
  int ind{};
  Node *tmp = front;
  while (tmp) {
    if (tmp->value == value_) { vec.push_back(ind); }
    ++ind;
    tmp = tmp->prev;
  }
  return vec;
}

template<class T>
typename BiDirectionalList<T>::Node *BiDirectionalList<T>::operator[](int ind) {
  Node *tmp = front;
  for (int i = 0; i < ind; ++i) {
    if (!tmp) { break; }
    tmp = tmp->prev;
  }
  return tmp;
}

template<class T>
void BiDirectionalList<T>::InsertAfter(BiDirectionalList::Node *elem, const T &value_) {
  Node *tmp = new Node(value_);
  Node *temp = elem->prev;
  elem->prev = tmp;
  temp->next = tmp;
  tmp->next = elem;
  tmp->prev = temp;
}

template<class T>
void BiDirectionalList<T>::InsertBefore(BiDirectionalList::Node *elem, const T &value_) {
  Node *tmp = new Node(value_);
  Node *temp = elem->next;
  elem->next = tmp;
  temp->prev = tmp;
  tmp->prev = elem;
  tmp->next = temp;
}

template<class T>
void BiDirectionalList<T>::Erase(BiDirectionalList::Node *elem) {
  Node *tmp = elem->prev;
  Node *temp = elem->next;
  tmp->next = temp;
  temp->prev = tmp;
  delete elem;
}

template<class T>
bool BiDirectionalList<T>::operator==(const BiDirectionalList<T> &rhs) const {
  Node *tmp = front;
  Node *temp = rhs.front;
  if (Size() != rhs.Size()) { return false; }
  while (tmp) {
    if (tmp->value != temp->value) { return false; }
    tmp = tmp->next;
    temp = temp->next;
  }
  return true;
}

template<class T>
bool BiDirectionalList<T>::operator!=(const BiDirectionalList<T> &rhs) const {
  return !(rhs == *this);
}

template<class T>
BiDirectionalList<T>::Node::Node(T value_) : value(value_), prev(nullptr), next(nullptr) {}

//!Stack
template<class T>
class Stack {
 private:
  BiDirectionalList<T> base_list;
 public:

  Stack();
  Stack(std::initializer_list<T>);
  void Push(const T &value_);
  void Pop();
  const T &Get();
  int Size();
  bool isEmpty();
  bool operator==(const Stack &rhs) const;
  bool operator!=(const Stack &rhs) const;

};
template<class T>
void Stack<T>::Push(const T &value_) {
  base_list.PushBack(value_);
}

template<class T>
bool Stack<T>::operator==(const Stack &rhs) const {
  return base_list == rhs.base_list;
}

template<class T>
bool Stack<T>::operator!=(const Stack &rhs) const {
  return !(rhs == *this);
}

template<class T>
void Stack<T>::Pop() {
  base_list.PopBack();
}

template<class T>
const T &Stack<T>::Get() {
  return base_list.Back()->value;
}

template<class T>
int Stack<T>::Size() {
  return base_list.Size();
}

template<class T>
bool Stack<T>::isEmpty() {
  return base_list.isEmpty();
}

template<class T>
Stack<T>::Stack() : base_list() {}
template<class T>
Stack<T>::Stack(std::initializer_list<T> a) : base_list(a) {}

#endif //CLION_CLION_CONTAINERS_H_
