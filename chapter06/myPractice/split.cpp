#include <string>
#include <vector>

using std::vector;
using std::string;

bool space(const char c) {
	return isspace(c);
}

bool notSpace(const char c) {
	return !space(c);
}

vector<string> split(const string & s) {
	vector<string> vec;

	string::const_iterator b = s.begin();
	while (b != s.end()) {
		while (space(*b) && b != s.end()) {
			++b;
		}

		string::const_iterator e = b;

		while (notSpace(*e) && e != s.end()) {
			++e;
		}

		vec.push_back(string(b, e));
		b = e;
	}

	return vec;
}

bool delimiter(const char c, const char d) {
	return c == d;
}

bool notDelimiter(const char c, const char d) {
	return !delimiter(c, d);
}

vector<string> split_delimiter(const string & s, const char d) {
	vector<string> vec;

	string::const_iterator b = s.begin();
	while (b != s.end()) {
		while (delimiter(*b, d) && b != s.end()) {
			++b;
		}

		string::const_iterator e = b;

		while (notDelimiter(*e, d) && e != s.end()) {
			++e;
		}

		vec.push_back(string(b, e));
		b = e;
	}

	return vec;
}
