#include<iostream>
#include<array>
#include<vector>

template<typename T> 
class Student
{

public:
	Student(T inf, std::string name) : Name{ name }, data{ inf } {}


	void data_out() const {
		std::cout << data << std::endl << Name << std::endl;
	}
private:
	T data;
	std::string Name;
};

auto count_lines(std::vector <std::string>& vline) {
	auto counter = [](std::vector <std::string>& vline) {
		int nums = 0;
		for (auto beg = vline.begin(); beg < vline.cend(); beg++) {
			if(beg[0] =="c")
				nums++;
		}return nums; };
	counter(vline);
	return counter;
}
int main() {
	Student<int> Dima{ 12, "dima" };
	Dima.data_out();
	std::vector <std::string> list_1 {"ere", "tutu", "cgg", "regexp"};
	
	return 0;
}
