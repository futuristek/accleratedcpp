#include "xref.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <istream>

using namespace std;

int main() {
	map<string, vector<int> > ret = xref(cin);
	for (auto & p : ret) {
		cout << p.first << " occurs on lines(s): ";
		auto line_it = p.second.begin();
		cout << *line_it;
		++line_it;
		while (line_it != p.second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
	}

	return 0;
}
