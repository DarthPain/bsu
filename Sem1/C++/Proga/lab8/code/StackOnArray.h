#ifndef CLION_CLION_STACKONARRAY_H_
#define CLION_CLION_STACKONARRAY_H_
#include <initializer_list>
template<class T>
class StackOnArray {
 private:
  int top;
  int size;
  T *arr[];

 public:
  StackOnArray() : top(-1), size(16), arr(new T[size]) {}
  ~StackOnArray() { delete[]arr; }
  StackOnArray(std::initializer_list<T>);

  int Size();
  bool isEmpty();
  void Push(const T &elem);
  T *Top();
  const T *Top() const;
  T Pop();

  bool operator==(const StackOnArray &rhs) const;
  bool operator!=(const StackOnArray &rhs) const;

};

template<class T>
StackOnArray<T>::StackOnArray(std::initializer_list<T>) {

}

template<class T>
int StackOnArray<T>::Size() {
  return (top + 1);
}

template<class T>
bool StackOnArray<T>::isEmpty() {
  return (top == -1);
}

template<class T>
void StackOnArray<T>::Push(const T &elem) {
  if (top < size) {
    arr[++top] = elem;
  } else {
    size *= 5 / 3;
    T *tmp[] = new T[size];
    for (int i = 0; i <= top; ++i) {
      tmp[i] = arr[i];
    }
    delete[] arr;
    arr = tmp;
  }
}

template<class T>
T *StackOnArray<T>::Top() {
  return arr[top];
}

template<class T>
const T *StackOnArray<T>::Top() const {
  return arr[top];
}

template<class T>
T StackOnArray<T>::Pop() {
  return arr[top--];
}
template<class T>
bool StackOnArray<T>::operator==(const StackOnArray &rhs) const {
  bool flag{true};
  if (top == rhs.top) {
    for (int i = 0; i < top; ++i) {
      if (arr[i] != rhs.arr[i]) {
        flag = false;
        break;
      }
    }
  } else { flag = false; }
  return flag;
}
template<class T>
bool StackOnArray<T>::operator!=(const StackOnArray &rhs) const {
  return !(rhs == *this);
}

#endif //CLION_CLION_STACKONARRAY_H_
