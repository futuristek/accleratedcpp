#include <istream>
#include <iostream>

std::istream& read(std::istream& is) {
	int a;
	is >> a;
	std::cout << a << std::endl;
	return is;
}

int main() {
	while (read(std::cin)) {}
}


