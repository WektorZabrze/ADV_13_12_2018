#include <string_view>
#include <iostream>


int main()
{
	std::string_view exampleView = "Jak tam zycie?";

	const char str[8] = {'A', ' ', 's', 'p', 'o', 'k', 'o', '\0' };
	std::string_view newView (str, 8);

	std::string_view emptyView;
	if (emptyView.data() == nullptr) {
		std::cout << "string_view nie wskazuje na zadne dane" << std::endl;
	}

	std::string cppString = "To fajnie";
	std::string_view lastOne (cppString);

	std::cout << exampleView << std::endl;
	std::cout << newView << std::endl;
	std::cout << lastOne << std::endl;

	return 0;
}