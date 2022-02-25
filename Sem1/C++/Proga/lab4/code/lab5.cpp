#include "lab5.h"
#include "iodata.h"

void Task1() {
    std::cout << "\nTask1 Max() overload!\n";
    int comp_type = 0;
    std::cout
            << "Which to compare:\n\t1 - 1 number(int)\n\t2 - 2 numbers(double)\n\t3 - 3 numbers(string)\n\t4 - vector<int>\n";
    std::cin >> comp_type;
    int a = 0;
    double b = 0;
    double b1 = 0;
    std::string c1 = "";
    std::string c2 = "";
    std::string c3 = "";
    int n = 0;
    std::cout << "Enter number of elements:";
    std::cin >> n;
    std::vector<int> d;

    switch (comp_type) {
        case 1:

            std::cout << "Enter element: ";
            std::cin >> a;
            std::cout << std::endl;
            std::cout << "Max of " << a << " is " << Max(a);
            break;
        case 2:

            std::cout << "Enter element: ";
            std::cin >> b;
            std::cout << std::endl;
            std::cout << "Enter element: ";
            std::cin >> b1;
            std::cout << std::endl;
            std::cout << "Max of {" << b << ", " << b1 << "} is " << Max(b, b1);
            break;
        case 3:

            std::cout << "Enter element: ";
            std::cin >> c1;
            std::cout << std::endl;
            std::cout << "Enter element: ";
            std::cin >> c2;
            std::cout << std::endl;
            std::cout << "Enter element: ";
            std::cin >> c3;
            std::cout << std::endl;
            std::cout << "Max of {" << c1 << ", " << c2 << ", " << c3 << "} is " << Max(c1, c2, c3);
            break;
        case 4:
            readVec(d, n);
            std::cout << "Max of {";
            print(d);
            std::cout << "} is " << Max(d);
            break;
        default:
            std::cout << "Wrong number, try again";
            Task1();
    }
}

void Task2() {
    std::cout << "\nTask2 Index of max elements in vector(recursion)!\n";
    int n = 0;
    std::cout << "Enter number of elements:";
    std::cin >> n;
    std::vector<int> vect;
    readVec(vect, n);
    print(vect);
    std::cout << " Index of max element in vector(real index + 1) = " << MaxInd(vect, 0) + 1;
}

void Task3() {
    std::cout << "\nTask3 Is line palindrome from j to k?\n";
    std::string s;
    int j = 0, k = 0;
    std::cout << "\nEnter string to test: ";
    std::cin >> s;
    std::cout << "Enter j,k - indexes for string to test: ";
    std::cin >> j >> k;
    //Change j and k if indexes are wrong
    if (j > k) {
        j += k;
        k = j - k;
        j -= k;
    }
    std::cout << "This string is " << (Palindrome(s, j, k) ? "" : "NOT")
              << " palindromic from " << j << " to " << k << "\n";
}

void Task4() {
    std::cout << "\nTask4 Numerical root!\n";
    int number = 0;
    std::cout << "\nEnter number for calculating it's numerical root: ";
    std::cin >> number;
    std::cout << "Numerical root of " << number << " = " << NumRoot(number) << "\n";
}

void Task5() {
    std::cout << "\nTask5 Bubble sort for vector: \n";
    std::cout << "Enter number of elements: ";
    int n = 0;
    std::cin >> n;
    std::vector<double> vector;

    readVec(vector, n);
    print(vector);
    BubbleSort(vector);
    print(vector);
}

void Task6() {
    std::cout << "\nTask6 Does a point belong to a given area?\n";
    std::pair<double, double> coords;
    std::cout << "Enter x(-6,6): ";
    std::cin >> coords.first;
    if (abs(coords.first) < 6) {
        std::cout << "Enter y: ";
    } else {
        std::cout << "Wrong x, try again!";
        Task6();
    }
    std::cin >> coords.second;

    std::cout << "\nPoint with coords (" << coords.first << ", " << coords.second
              << ") ";
    if (IsInsideArea(coords.first, coords.second)) {
        std::cout << "belongs to a given area!\n";
    } else {
        std::cout << "does NOT belong to a given area!\n";
    }
}


template<class T>
T Max(T a) { return a; }

template<class T>
T Max(T a, T b) { return (a > b) ? a : b; }

template<class T>
T Max(T a, T b, T c) { return Max(Max(a, b), c); }

template<class T>
T Max(std::vector<T> vec) { return vec.at(MaxInd(vec, 0)); }

template<class T>
int MaxInd(std::vector<T> vec, int ind_now) {
    if (vec.size() - 1 > ind_now) {
        int current = MaxInd(vec, ind_now + 1);
        return (vec.at(current) > vec.at(ind_now)) ? current : ind_now;
    } else {
        return ind_now;
    }
}

bool Palindrome(std::string line, int ind_begin, int ind_end) {
    if (abs(ind_begin - ind_end) > 1) {
        if (line.at(ind_begin) == line.at(ind_end)) {
            return Palindrome(line, ind_begin + 1, ind_end - 1);
        } else {
            return false;
        }
    } else {
        return (line.at(ind_begin) == line.at(ind_end));
    }
}


int NumRoot(int num) {
    if (num > 9) {
        return NumRoot(num / 10 + num % 10);
    } else {
        return num;
    }
}

template<class T>
void BubbleSort(std::vector<T> &vec) {
    vec.shrink_to_fit();
    int n = vec.size();
    T tmp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec.at(j) > vec.at(j + 1)) {
                tmp = vec.at(j);
                vec.at(j) = vec.at(j + 1);
                vec.at(j + 1) = tmp;
            }
        }
    }
}


bool IsInsideArea(double x, double y) {
    if (abs(x) <= 5) {
        if (x > 0 && y > 0) {
            return (y < graph_parabola_X_top(x) && y < graph_circle_top(x) && (x < M_PI ? y < graph_tan(x) : true));
        }
        if (x < 0 && y > 0) {
            return (y > graph_circle_top(x) && (x < -M_PI ? y < graph_tan(x) : true));
        }
        if (x < 0 && y < 0) {
            return (y < graph_lin(x) && y > graph_circle_bot(x) && (x > -M_PI ? y < graph_tan(x) : true));
        }
        if (x > 0 && y < 0) {
            return false;
        }
    }
    return false;
}

double graph_parabola_X_top(double x) {
    return ((1.5 + sqrt(2.25 + 4 * x + 10)) / 2);
}

double graph_parabola_X_bot(double x) {
    return ((1.5 - sqrt(2.25 + 4 * x + 10)) / 2);
}

double graph_circle_top(double x) {
    return sqrt(25 - x * x);
}

double graph_circle_bot(double x) {
    return -sqrt(25 - x * x);
}

double graph_lin(double x) {
    return (-2 * x - 7);
}

double graph_tan(double x) {
    return tan(x / 2.);
}