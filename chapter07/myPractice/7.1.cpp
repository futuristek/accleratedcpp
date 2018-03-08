#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	map<string, int> counters;
	map<int, vector<string> > count_map;

	while (cin >> s) {
		++counters[s];
	}

	// map count to vector of strings
	for (auto & p : counters) {
		count_map[p.second].push_back(p.first);
	}

	cout << endl;
	for (auto & p : count_map) {
		cout << "Occurence: " << p.first << endl;
		for (auto & str : p.second) {
			cout << "\t" << str << endl;
		}
	}
}
