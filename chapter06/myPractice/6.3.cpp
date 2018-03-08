#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <chrono>

using namespace std;

int main() {
	const int size = 10;
	vector<int> u(size, 100);
	vector<int> v;

	auto t_start = std::chrono::system_clock::now();
	v.reserve(size);
	copy(u.begin(), u.end(), back_inserter(v));
	auto t_end = std::chrono::system_clock::now();
	chrono::duration<double> t = t_end - t_start;
	cout << "It runs for " << t.count() << " seconds" << endl;

	t_start = std::chrono::system_clock::now();
	vector<int> g = u;
	t_end = std::chrono::system_clock::now();
	t = t_end - t_start;
	cout << "It runs for " << t.count() << " seconds" << endl;

	for (auto & i : g) cout << i << " ";
	cout << endl;

}
