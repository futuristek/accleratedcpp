#include <iostream>
#include "Str.hpp"
#include <string>

int main() {
	Str s1(10, 'a');
	Str s2("hello world!");
	std::string a("paly game");
	Str s3(a.begin(), a.end());
	Str s4 = "go go curry";

	s1 += s2;

	Str s5 = s2 + s3;

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	std::cout << s5 << std::endl;
	return 0;
}
