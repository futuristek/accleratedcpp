#include "Vec.hpp"
#include <iostream>

using namespace std;

int main() {
	Vec<int> a;
	Vec<int> b(10, 10);
	a = b;
	a.push_back(1);

	for (auto & x : a) {
		cout << x << " ";
	}
	cout << endl;

	a.erase(a.begin());
	
	for (auto & x : a) {
		cout << x << " ";
	}
	cout << endl;

	a.erase(a.end() - 1);
	for (auto & x : a) {
		cout << x << " ";
	}
	cout << endl;

	a.clear();
	a.push_back(111);
	for (auto & x : a) {
		cout << x << " ";
	}
	cout << endl;


	return 0;
}
