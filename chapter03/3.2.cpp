#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int a;
    std::vector<int> vec;
    while (std::cin >> a)
    {
        vec.push_back(a);
    }
    
    std::sort(vec.begin(), vec.end());
    std::cout << "Sorted input numbers: " << std::endl;
    
    for (auto & i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::vector<unsigned int> quantile_index; 

    for (unsigned n = 1; n <= 4; ++n)
    {
        quantile_index.push_back(std::ceil((double(n)/4)*vec.size()) - 1);
    }

    for (auto & i : quantile_index)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}