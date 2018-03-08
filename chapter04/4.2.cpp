#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::vector<int> vec;
    while (std::cin >> n)
    {
        std::cout << std::setw(3) << n << " " << std::setw(5) << n*n << std::endl;
    }
}