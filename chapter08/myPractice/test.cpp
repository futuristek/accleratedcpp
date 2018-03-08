#include "../split.h"
#include <list>
#include <string>
#include <iostream>

int main() {
	std::list<string> word_list = {"a", "b"};
	std::string s = "hello world";
	split(s, word_list.begin());
	for (auto & w : word_list) {
		std::cout << w << std::endl;
	}
}
