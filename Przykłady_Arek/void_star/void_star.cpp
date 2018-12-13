#include <iostream>
#include <vector>

//#define ERROR

int main()
{
	int test_int = 5;
	void* ptr = &test_int;

	#ifdef ERROR
		*ptr; // nie można zrobić dereferencji na void*
	#endif

	int* ptrToInt = static_cast<int*>(ptr);
	std::cout << *ptrToInt << std::endl;

	// Problem jest taki, że nie mamy nigdzie informacji o 
	// faktycznym typie. Ponadto język pozwala nam na dokonanie
	// błędnej (z punktu widzenia typów) konwersji
	std::vector<double>* ptrA = static_cast<std::vector<double>*>(ptr);
	std::cout << (*ptrA).size() << std::endl; // !!!

}