/*
#ifndef CLION__BIDIRECTIONALLIST_H_
#define CLION__BIDIRECTIONALLIST_H_

#include <initializer_list>
#include <vector>
template<class T>
class BiDirectionalList {
 public:
  struct Node {
   public:
    T value;
   private:
    Node *next;
    Node *prev;
    Node(T value, Node *next, Node *prev);
    Node();
  };

 public:
  BiDirectionalList();
  BiDirectionalList(std::initializer_list<T>);
  ~BiDirectionalList();

  int Size();
  bool isEmpty();

  void PushFront(const T &value);
  void PushBack(const T &value);

  Node *Front();
  Node *Back();

  void PopFront();
  void PopBack();

  std::vector<T> ToVector();

  int Find(const T &value);
  std::vector<int> FindAll(const T &value);

  //!Node*operator[]();

  void InsertBefore(Node *element, const T &value);
  void InsertAfter(Node *element, const T &value);

  void Erase(Node *element);

 private:
  Node *head;
  Node *tail;

};

template<class T>
BiDirectionalList<T>::Node::Node(T value, BiDirectionalList::Node *next, BiDirectionalList::Node *prev)
    :value(value), next(next), prev(prev) {}
template<class T>
BiDirectionalList<T>::Node::Node():value(0), next(nullptr), prev(nullptr) {}

template<class T>
BiDirectionalList<T>::BiDirectionalList() {
  std::cout << "Hello!";
  barrier = new Node(nullptr, nullptr, nullptr);
}

template<class T>
int BiDirectionalList<T>::Size() {
  int count{0};
  Node *tmp = head;
  while (tmp->next != barrier) {
    ++count;
    tmp = tmp->next;
  }
  return count;
}
template<class T>
BiDirectionalList<T>::~BiDirectionalList() {
  std::cout << "Hello2!";
*/
/*  delete barrier;
  delete head;
  delete tail;*/
#include <map>
#include <set>
/*

}
template<class T>
bool BiDirectionalList<T>::isEmpty() {
  return (head->next == barrier);
}
template<class T>
void BiDirectionalList<T>::PushFront(const T &value) {
  Node *tmp = head;
  head = Node(value, tmp, barrier);
  tmp->prev = head;
}
template<class T>
void BiDirectionalList<T>::PushBack(const T &value) {
  Node *tmp = tail;
  //!do I need tail->prev->next = tmp?
  tail = Node(value, barrier, tmp);
  tmp->next = tail;
}

#endif //CLION__BIDIRECTIONALLIST_H_
*/
/*
template<class T>
class SharedPtr {
 private:
  class Table {
   private:
    class ListOfPointers {
     private:
      std::set<SharedPtr<T> *> pointers;
     public:
      ListOfPointers() : pointers(std::set<SharedPtr<T> *>()) {}
      void insert(SharedPtr<T> *value) { pointers.insert(value); }
//bool find(SharedPtr<T>* value) { return pointers.find(value) != pointers.end(); }
      void erase(SharedPtr<T> *value) { pointers.erase(value); }
      void nullization() { for (auto p : pointers) { p->object = nullptr; }}
      bool empty() { return pointers.empty(); }
    };
    std::map<T *, ListOfPointers> objects;
   public:
    Table() : objects(std::map<T *, ListOfPointers>()) {}
    ListOfPointers &operator[](T *key) {
      if (objects.find(key) == objects.end()) {
        objects.emplace(key, ListOfPointers());
      }
      return objects[key];
    }
    void erase(T *key) { objects.erase(key); }
  };

  T *object;
  static Table table = Table();
};*/