/*
 Prosty przykład obrazujacy fakt, ze variant wywoluje destruktory
 przy zmianie aktywnego typu
*/

#include <iostream>
#include <variant>

class IntLoudWrapper
{
public:
	IntLoudWrapper(int data = 0) : m_data(data) {
		std::cout << "IntLoudWrapper(" << m_data << ")" << std::endl;
	}

	~IntLoudWrapper() {
		std::cout << "~IntLoudWrapper()" << std::endl;
	}

private:
	int m_data;
};

class FloatLoudWrapper
{
public:
	FloatLoudWrapper(float data = 0.0) : m_data(data) {
		std::cout << "FloatLoudWrapper(" << m_data << ")" << std::endl;
	}

	~FloatLoudWrapper() {
		std::cout << "~FloatLoudWrapper()" << std::endl;
	}

private:
	float m_data;
};

int main()
{
	std::variant<IntLoudWrapper, FloatLoudWrapper> testVariant;

	testVariant = FloatLoudWrapper(1.5);

	return 0;
}