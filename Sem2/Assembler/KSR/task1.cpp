#include <iostream>

extern "C" void _cdecl proc1();
extern "C" void _cdecl proc2(double* a, double* b, double* c, double* res);

int main() {
    double* result = new double[3];
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
    double *a = new double(0.17), 
		   *b = new double(0.25),
           *c = new double(0.39);

	std::cout << sizeof(result) << std::endl;
	_asm {
		mov eax, result
		mov ebx, b
		push ebx
		call proc1
		add esp,4
	}


    std::cout << "Elements are " << result[0] << ", " << result[1] << ", "
              << result[2] << std::endl;

	proc2(a, b, c, result);
    std::cout << "Elements are " << result[0] << ", " << result[1] << ", "
              << result[2] << std::endl;

	delete[] result;
	system("pause");
	return 0;
}