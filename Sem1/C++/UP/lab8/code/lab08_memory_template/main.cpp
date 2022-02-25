#include <iostream>

#include "containers.h"
#include "shared_ptr.h"

using containers::BiDirectionalList;
using containers::Container;
using shared_ptr::SharedPtr;

// YOUR_CODE_HERE

int main() {
  SharedPtr<Container<int>> container;
  Read(&container);
  const SharedPtr<BiDirectionalList<int>> list = ConvertToList(container);
  PrintStats(*list);
  return 0;
}
