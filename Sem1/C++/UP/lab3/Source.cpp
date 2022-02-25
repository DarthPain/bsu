#include <cmath>
#include <iostream>
#include <cmath>

bool isPrime(unsigned long long n);
bool isPerfect(unsigned long long n);
bool isDivisible(unsigned long long n);
unsigned long long delMin(unsigned long long num);
unsigned long long powMy(int x, int power);
double powMy(double x, int power);
double myTaylor(double x, double epsilon);
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();

int main() {

	int t_n = 0;
  std::cout << "Enter task number(1-5): ";
  std::cin >> t_n;
  switch (t_n) {
    case 1:
      // task1 var7 Mersen numbers
      Task1();
      break;
    case 2:
      // Task2 perfect numbers on segment
      Task2();
      break;
    case 3:
      // Task 3 delete min digit
      Task3();
      break;
    case 4:
      // Task 4 is divisible
      Task4();
      break;
    case 5:
      // Task5 Taylor series
      Task5();
      break;
    default:
      std::cout << "Wrong task number, try again";
      break;
  }

  system("pause");
  return 0;
}



bool isPrime(unsigned long long n) {
  int sum = 0;
  for (int i = 2; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      sum++;
    }
  }
  return !sum;
}

bool isPerfect(unsigned long long n) {
  unsigned long long sum = 0;
  for (unsigned long long i = 1; i < n; ++i) {
    if (n % i == 0) {
      sum += i;
    }
  }

  return (sum == n) ? true : false;
}

unsigned long long delMin(unsigned long long num) { 
	int min_digit = num % 10;
	unsigned long long num_copy = num;
    int digit_number = 1;
    while (num_copy > 1) {
		 if (num_copy % 10 < min_digit) {
				min_digit = num_copy % 10;
			}
		num_copy /= 10;
        digit_number++;
	}

	unsigned long long result = 0;
    int power = 0;
	
	for (int i = 0; i < digit_number; ++i) {
          if (num % 10 != min_digit) {
            result += powMy(10, power) * (num % 10);
            ++power;
		  }
          num /= 10;
	}

	return result;
}

unsigned long long powMy(int x, int power) {
  int x1 = x;
  if (power > 1) {
  for (int i = 1; i < power; ++i) {
    x *= x1;
  }
  } else if (power == 0) {
    return 1;
  }
  return x;
}

double powMy(double x, int power) {
  double x1 = x;
  if (power > 1) {
    for (int i = 1; i < power; ++i) {
      x *= x1;
    }
  } else if (power == 0) {
    return 1;
  }
  return x;
}

bool isDivisible(unsigned long long n) { 
	int sum = 0;
  unsigned long long n_copy = n;
  while (n_copy >= 1) {
    sum += n_copy % 10;
    n_copy /= 10;
  }

  return (n % sum == 0) ? 1 : 0;
}

double myTaylor(double x, double epsilon) {
  double xn = 1;
  double sum = 1;

  for (int i = 1; abs(xn) > epsilon; ++i) {
    xn = ((i % 2 == 0) ? 1 : -1) * (i + 1) * (i + 2) / 2. *  powMy(x,i);
    sum += xn;
  }

return sum;
}

void Task1() 
{
  unsigned long long n, amount = 0;
  std::cout << "Task1 v7: Mersen numbers\nEnter n(positive integer) ";
  std::cin >> n;
  for (int i = 2; amount <= n; ++i) {
    if (powMy(2, i) - 1 >= ULLONG_MAX) {
      std::cout << "Out of range. Can't find any more numbers!";
      break;
    }
    if (isPrime(i)) {
      std::cout << powMy(2, i) - 1 << "\n";
      amount++;
    }
  }
}

void Task2() 
{
  unsigned long long a, b;
  std::cout << "\n\nTask2 v7: perfect numbers\nEnter a, b(segment borders, "
               "positive integers) ";
  std::cin >> a >> b;
  if (a < b) {
    std::cout << "\nPerfect number from " << a << " to " << b << "are: \n";
    for (unsigned long long i = a; i <= b; ++i) {
      if (isPerfect(i)) {
        std::cout << i << "\n";
      }
    }
  } else {
    std::cout << "a must be less than b\n";
  }
}

void Task3()
{
  unsigned long long num;
  std::cout
      << "\n\nTask3 v7: delete min digit in number\nEnter n(positive integer) ";
  std::cin >> num;
  if (num < ULLONG_MAX) {
    std::cout << delMin(num) << '\n';
  } else {
    std::cout << "Out of range";
  }
}

void Task4()
{
  unsigned long long number;
  std::cout << "\n\nTask4 v7(+13): can a number be devide by its digits "
               "sum\nEnter n(positive integer) ";
  std::cin >> number;
  std::cout << number << (isDivisible(number) ? " can" : " can NOT")
            << " be devided by its digits sum\n";
}

void Task5()
{
  double series_sum = 0;
  int k;
  double x;
  double epsilon;
  std::cout << "\n\nTask5 v7: Taylor series for 1/(1+x)3\nEnter x(-1,1) and K "
               "for epsilon(0 < Epsilon < 10^-k, where k = 0,1,...,n) ";
  std::cin >> x >> k;
  if (abs(x) <= 1) {
  
  epsilon = powMy(0.1, k);
  std::cout << "myTaylor(" << x << ", " << epsilon << ") - 1/(1-"
            << x << ")^3 = "
            << myTaylor(x, epsilon) - 1. / ((1 + x) * (1 + x) * (1 + x))
            << '\n';
  } else {
    std::cout << "Wrong x value, try again!";
    Task5();
  }
}