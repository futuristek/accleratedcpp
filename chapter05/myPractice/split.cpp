#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    //invariant i, we have processed [original i, current i)
    while (i != s.size())
    {
        //the original i to current i are all spaces
        while (i != s.size() && isspace(s[i]))
        {
            ++i;
        }

        string_size j = i;

        //invariant j, original j to current j are all non-space
        while (j != s.size() && !isspace(s[j]))
        {
            ++j;
        }

        ret.push_back(s.substr(i, j - i));
		i = j;
    }

    return ret;
}

int main()
{
    string s;
    while (std::getline(std::cin, s))
    {
        vector<string> words = split(s);
        for (auto w: words)
		{
			std::cout << w << " ";	
		}
        std::cout << std::endl;
    }
    return 0;
}
