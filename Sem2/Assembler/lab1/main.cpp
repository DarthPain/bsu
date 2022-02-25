#include <iostream>

int main() {
  std::cout << "Hello, World!" << std::endl;
  __int16 A1 = 1, A2 = 1, A3 = 1, B1 = 1, B2 = 1, B3 = 1, C1, C2, C3;
  __asm(".intel_syntax noprefix \n"
        "mov ax, A1\n"
        "add ax, B2\n"
        "mov C1, ax\n"
        ".att_syntax            \n");
  std::cout << "First attempt : c1 = " << C1 << '\n';
  return 0;
}
