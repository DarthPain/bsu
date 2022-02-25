#ifndef CONTAINERS_H_
#define CONTAINERS_H_

#include <utility>
#include <vector>
#include <cassert>

namespace containers {

// --------------------------------------------------------------------------

// Тут следует расположить код решения задачи 1 (BiDirectionalList).

// --------------------------------------------------------------------------

// Тут следует расположить код решения задачи 2 (Queue / Stack).

// --------------------------------------------------------------------------

// Раскоментируйте нужные строки ниже для выбора варианта

enum class Variant {
  kQueue,
  kStack,
};

Variant GetVariant() {
  // return Variant::kQueue;
  // return Variant::kStack;
}

// template<typename T>
// using Container = Queue<T>;

// template<typename T>
// using Container = Stack<T>;

// --------------------------------------------------------------------------

}  // namespace containers

#endif  // CONTAINERS_H_
