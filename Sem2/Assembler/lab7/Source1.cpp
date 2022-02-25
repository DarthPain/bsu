#include <iostream>

extern "C" void __fastcall spacecutter(int,char[]); 

int main() {
  char s1[] = "D 4wac        On        aI    P";
  spacecutter(29,s1);
  std::cout << s1 <<  "!"  << std::endl;
  system("pause");
  return 0;
}