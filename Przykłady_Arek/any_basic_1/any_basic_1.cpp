#include <any>
#include <iostream>
#include <vector>

int main()
{
	int test_int = 5;
	std::any anyExample = test_int;

	try 
	{
		int value = std::any_cast<int> (anyExample);
		std::cout << "Cast worked: " << value << std::endl;
	}
	catch (const std::bad_any_cast& e)
	{
		std::cout << e.what() << std::endl;
	}

	try 
	{
		auto value = std::any_cast<std::vector<double>> (anyExample);
		std::cout << "Cast worked" << std::endl;
	}
	catch (const std::bad_any_cast& e) 
	{
		std::cout << e.what() << std::endl;
	}
}