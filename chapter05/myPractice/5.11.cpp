#include <iostream>
#include <string>
#include <list>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;


set<char> get_asc(const string & word) {
	static const set<char> ascenders = {'b', 'd', 'f', 'h', 'k', 'l'};
	set<char> ret;
	copy_if(word.begin(), word.end(), inserter(ret, ret.end()), [&](const char & c){return ascenders.find(c) != ascenders.end();});
	return ret;
}

set<char> get_desc(const string & word) {
	static const set<char> descenders = {'g', 'j', 'p', 'q', 'y'};
	set<char> ret;
	copy_if(word.begin(), word.end(), inserter(ret, ret.end()), [&](const char & c){return descenders.find(c) != descenders.end();});
	return ret;
}

int main() {
	string in;
	while (cin >> in) {
		auto a = get_asc(in);
		if (a.size() != 0) {
			cout << "Ascenders: " << endl;
			for (auto & c : a) {
				cout << c << " ";
			}
			cout << endl;
		}
		auto d = get_desc(in);
		if (d.size() != 0) {
			cout << "Descenders: " << endl;
			for (auto & c : d) {
				cout << c << " ";
			}
			cout << endl;
		}
	}
}
