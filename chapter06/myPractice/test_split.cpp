#include "split.hpp"
#include <iostream>

int main() {
	std::string s;
	while (getline(std::cin, s)) {
		std::vector<std::string> words;
		words = split_delimiter(s, '_');
		for (auto & s : words) {
			std::cout << s << std::endl;
		}
	}
	return 0;
}
