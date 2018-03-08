#include <string>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

string concat(const vector<string> & s) {
	string init = "";
	return accumulate(s.begin(), s.end(), init);
}

int main() {
	vector<string> vec;
	for (int i = 0; i < 10; ++i) {
		vec.push_back(to_string(i));
	}
	cout << concat(vec) << endl;
}
