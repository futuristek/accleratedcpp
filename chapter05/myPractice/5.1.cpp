#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(string s, vector<string> & r)
{
    r.push_back(s);
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if (*it == ' ')
        {
            string ls = s.substr(0, distance(s.begin(), it));
            string rs = s.substr(distance(s.begin(), it) + 1, distance(it, s.end()));
            string rotated_str = rs + " " + ls;
            r.push_back(rotated_str);
        }
    }
}

void print(const vector<string> & v, const vector<string> & raw, const int max_size)
{
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        string line = *it;
        for (auto & s : raw)
        {
            if (s == line)
            {
                cout.width(max_size);
                cout << "\t" << line << endl;
                continue;
            }
        }
        for (auto it_l = line.begin(); it_l != line.end(); ++it_l)
        {
            if (*it_l == ' ')
            {
                string ls = line.substr(0, distance(line.begin(), it_l));
                string rs = line.substr(distance(line.begin(), it_l) + 1, distance(it_l, line.end()));
                string new_line = rs + " " + ls;
                for (auto & s : raw)
                {
                    if (s == new_line)
                    {
                        cout.width(max_size);
                        cout << rs << "\t" << ls << endl;
                    } 
                }
            }
        }
    }
}

int main()
{
    ifstream in("input.txt", ios_base::in);
    string line;
    vector<string> rotated;
    vector<string> raw;
    int max_size = 0;
    while(getline(in, line))
    {
        raw.push_back(line);
        if (line.length() > max_size) max_size = line.length();
        rotate(line, rotated);
    }
    sort(rotated.begin(), rotated.end(), [](string a, string b){return tolower(a[0]) < tolower(b[0]);});
    print(rotated, raw, max_size);
}