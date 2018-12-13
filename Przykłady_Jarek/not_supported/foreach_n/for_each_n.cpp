#include <iostream>
#include <algorithm>
#include <vector>

struct MyUnaryFun1{
	template <typename T>
	void operator()(T& item){
		item+=3;
	}
	MyUnaryFun1() = default;
	MyUnaryFun1(const MyUnaryFun1& to_cpy) = delete;
	MyUnaryFun1(MyUnaryFun1&& to_move) = default;
};

struct MyUnaryFun2{
	template <typename T>
	void operator()(T& item){
		item+=3;
	}	
};

int main(){
	std::vector<int> items{1,2,3,4,5};
	std::for_each_n(items.begin(), 3, MyUnaryFun1());
}
