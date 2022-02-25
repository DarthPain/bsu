#include <iostream>

int main() {
  int x{}, res{};
  // std::cin >> std::hex >> x;
  // std::cout << std::dec << x << std::endl;
  std::cout << "Enter number to test amount of 1 in binary form" << std::endl;
  std::cin >> x;
  __asm {
    mov eax, x;
    xor ecx, ecx;
    shl eax, 1;
  _loop:
    shr eax, 1;
    cmp eax, 0;
    jz _out;
    test eax, 1;
    jz _loop;
    inc ecx;
    jmp _loop;
  _out:
    mov res, ecx;
  }

  std::cout << "There are " << res << " single digits\n";
  system("pause");
  return 0;
}