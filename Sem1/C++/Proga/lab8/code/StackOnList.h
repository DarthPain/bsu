#ifndef CLION_CLION_STACKONLIST_H_
#define CLION_CLION_STACKONLIST_H_
#include <initializer_list>
template<class T>
class StackOnList {
 public:
  struct NodeStack {
    friend class StackOnList;
   private:
    NodeStack *prev;

    explicit NodeStack(T value) : value_(value), prev(nullptr) {}

   public:
    T value_;
  };

  StackOnList();
  ~StackOnList();
  StackOnList(const StackOnList &stack_on_list);
  StackOnList(StackOnList &&stack_on_list) noexcept;
  StackOnList(std::initializer_list<T>);
  int Size();
  bool isEmpty();
  void Push(const T &value);
  NodeStack *Top();
  const NodeStack *Top() const;
  T Pop();

  StackOnList &operator=(const StackOnList &stack_on_list);

  bool operator==(StackOnList &stack2);
  bool operator!=( StackOnList &stack2);

 private:
  NodeStack *top;

};

template<class T>
StackOnList<T>::StackOnList() : top{nullptr} {}

template<class T>
StackOnList<T>::StackOnList(const StackOnList &stack_on_list) {
  auto *temp = new NodeStack(stack_on_list.top->value_);
  top = temp;
  NodeStack *tmp = stack_on_list.top;
  while (tmp->prev != nullptr) {
    tmp = tmp->prev;
    temp->prev = new NodeStack(tmp->value_);
    temp = temp->prev;
  }
}

template<class T>
StackOnList<T>::StackOnList(StackOnList &&stack_on_list) noexcept {}

template<class T>
StackOnList<T>::StackOnList(std::initializer_list<T>) {}

template<class T>
void StackOnList<T>::Push(const T &value) {
  auto *node_stack = new NodeStack(value);
  node_stack->prev = top;
  top = node_stack;
}

template<class T>
int StackOnList<T>::Size() {
  int size{};
  NodeStack *tmp = top;
  while (tmp != nullptr) {
    tmp = tmp->prev;
    ++size;
  }
  return size;
}

template<class T>
bool StackOnList<T>::isEmpty() {
  return !top;
}

template<class T>
typename StackOnList<T>::NodeStack *StackOnList<T>::Top() {
  return top;
}
template<class T>
const typename StackOnList<T>::NodeStack *StackOnList<T>::Top() const {
  return top;
}

template<class T>
T StackOnList<T>::Pop() {
  if (!isEmpty()) {
    T value = top->value_;
    NodeStack *tmp = top;
    top = top->prev;
    delete tmp;

    return value;
  } else { return T{}; }
}

template<class T>
StackOnList<T>::~StackOnList() {
  while (top != nullptr) {
    Pop();
  }
}
template<class T>
bool StackOnList<T>::operator==(StackOnList &stack2) {
  bool flag = true;
  if (Size() != stack2.Size()) { flag = false; }
  NodeStack *tmp = Top();
  NodeStack *temp = stack2.Top();
  while (tmp->prev != nullptr) {
    if (tmp->value_ != temp->value_) { flag = false; }
    tmp = tmp->prev;
    temp = temp->prev;
  }
  return flag;
}

template<class T>
bool StackOnList<T>::operator!=(StackOnList &stack2) {
  return !((*this) == stack2);
}

template<class T>
StackOnList<T> &StackOnList<T>::operator=(const StackOnList &stack_on_list) {
  if (this == stack_on_list) { return (*this); }
  NodeStack *temp = stack_on_list.Top();
  while (top != nullptr) {
    Pop();
  }
  while (temp->prev != nullptr) {
    Push(temp->value_);
    temp = temp->prev;
  }
  return (*this);
}

#endif //CLION_CLION_STACKONLIST_H_
