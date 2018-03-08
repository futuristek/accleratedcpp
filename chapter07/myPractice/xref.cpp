#include <map>
#include <string>
#include <vector>
#include <istream>
#include "../../chapter06/myPractice/split.hpp"

using namespace std;

map<string, vector<int> >
xref (istream& in, vector<string> find_words(const string&) = split) {
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;

	while(getline(in, line)) {
		++line_number;

		vector<string> words = find_words(line);
		for (auto it = words.begin(); it != words.end(); ++it) {
			if (ret.find(*it) == ret.end())
				ret[*it].push_back(line_number);
		}
	}
	return ret;
}
