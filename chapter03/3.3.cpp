#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, unsigned int> hist;
    std::string in;
    while(std::cin >> in)
    {
        if (hist.find(in) == hist.end())
        {
            hist[in] = 1;
        } else
        {
            hist[in] += 1;
        }
    }
    for (auto & v : hist)
    {
        std::cout << v.first << " " << v.second << std::endl;
    }
}