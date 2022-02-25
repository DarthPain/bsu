#ifndef CLION_CLION_SHAREDPTR_H_
#define CLION_CLION_SHAREDPTR_H_

#include <map>
#include <set>
template<class T>
class SharedPtr {
 private:
  T *ptr_obj;
  static std::set<SharedPtr<T> *> all_shared_ptr;
  static std::map<T *, int> all_pointers;
 public:

  SharedPtr();
  explicit SharedPtr(T *ptr_value);
  ~SharedPtr();

  SharedPtr<T> &operator=(T *ptr_value_);

  T *Get();
  const T *Get() const;
  void Release();

  T &operator*();
  T *operator->();
  const T &operator*() const;
  const T *operator->() const;

  bool operator==(const SharedPtr<T> &rhs) const;
  bool operator!=(const SharedPtr<T> &rhs) const;
  bool operator==(const T *) const;
  bool operator!=(const T *) const;

};

template<class T>
SharedPtr<T>::SharedPtr() : ptr_obj(nullptr) { all_shared_ptr.insert(this); }

template<class T>
SharedPtr<T>::SharedPtr(T *ptr_value_) : ptr_obj(ptr_value_) {
  all_shared_ptr.insert(this);
  typename std::map<T *, int>::iterator iter = all_pointers.find(ptr_value_);
  if (iter == all_pointers.end()) {
    all_pointers.insert(std::pair<T *, int>(ptr_value_, 1));
  } else {
    iter->second += 1;
  }
}

template<class T>
SharedPtr<T>::~SharedPtr() {
  if (all_pointers.at(ptr_obj) <= 1) {
    //std::cout << "deleting shared_ptr\n";
    all_shared_ptr.erase(this);
    all_pointers.erase(ptr_obj);
    delete ptr_obj;
    ptr_obj = nullptr;
  } else {
    //std::cout << "No deleting!\n";
    all_pointers.at(ptr_obj) -= 1;
  }

}

template<class T>
T *SharedPtr<T>::Get() {
  return ptr_obj;
}

template<class T>
void SharedPtr<T>::Release() {
  typename std::map<T *, int>::iterator iter = all_pointers.find(ptr_obj);
  int count = iter->second;
  for (auto &item : all_shared_ptr) {
    if ((item != this) && (item->ptr_obj == ptr_obj)) {
      item->ptr_obj = nullptr;
    }
  }
  ptr_obj = nullptr;
  all_pointers.insert(std::pair<T *, int>(ptr_obj, count));
}

template<class T>
T &SharedPtr<T>::operator*() {
  return (*ptr_obj);
}

template<class T>
T *SharedPtr<T>::operator->() {
  return ptr_obj;
}

template<class T>
const T &SharedPtr<T>::operator*() const {
  return (*ptr_obj);
}

template<class T>
const T *SharedPtr<T>::operator->() const {
  return ptr_obj;
}

template<class T>
const T *SharedPtr<T>::Get() const {
  return ptr_obj;
}

template<class T>
bool SharedPtr<T>::operator==(const SharedPtr &rhs) const {
  return ptr_obj == rhs.ptr_obj;
}

template<class T>
bool SharedPtr<T>::operator!=(const SharedPtr &rhs) const {
  return !(rhs == *this);
}

template<class T>
bool SharedPtr<T>::operator==(const T *tmp) const {
  return (ptr_obj == tmp);
}

template<class T>
bool SharedPtr<T>::operator!=(const T *tmp) const {
  return (ptr_obj != tmp);
}

template<class T>
SharedPtr<T> &SharedPtr<T>::operator=(T *ptr_value_) {
  ptr_obj = ptr_value_;
  all_shared_ptr.insert(this);
  typename std::map<T *, int>::iterator iter = all_pointers.find(ptr_value_);
  if (iter == all_pointers.end()) {
    all_pointers.insert(std::pair<T *, int>(ptr_value_, 1));
  } else {
    iter->second += 1;
  }
  return (*this);
}

template<class T>
std::map<T *, int> SharedPtr<T>::all_pointers{};

template<class T>
std::set<SharedPtr<T> *> SharedPtr<T>::all_shared_ptr{};

#endif //CLION_CLION_SHAREDPTR_H_
