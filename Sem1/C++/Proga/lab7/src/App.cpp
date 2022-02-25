#include "MoneyEnglish.h"
#include <iostream>

class App {

 public:
  static void Start() {
    std::cout << "This program works!\n";
    MoneyEnglish money{17864512, 11, 10.7};
    std::cout << money << "\n";
    // money.SetPenny(10);
    //money.SetShilling(5);
    money.SetPound(-1);

    money = -money;
    std::cout << money << "\n";

    money = money + money;
    // money += money
    std::cout << money << "\n";

    money -= -money;
    // money = money - money
    std::cout << money << "\n";
  }
};