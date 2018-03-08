#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string & s)
{
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

void test(const string & s)
{
    if (isPalindrome(s))
        cout << s << " is a parlindrome." << endl;
    else
        cout << s << " is not a parlindrome." << endl;
}

int main()
{
    test("hello");
    test("radar");
}