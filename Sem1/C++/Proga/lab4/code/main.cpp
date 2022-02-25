#include "lab5.h"
#include "iodata.h"

int main() {

    int t_n = 0;
    std::cout << "Please, enter task number(1-6): ";
    std::cin >> t_n;
    switch (t_n) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;
        case 4:
            Task4();
            break;
        case 5:
            Task5();
            break;
        case 6:
            Task6();
            break;
        default:
            std::cout << "Wrong task number!\n";
            break;
    }
    return 0;
}