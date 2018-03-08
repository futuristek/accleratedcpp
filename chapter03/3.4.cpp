#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string in;
    std::pair<std::string, std::string> mm;
    bool first = true;
    while (std::cin >> in)
    {
        if (first)
        {
            mm.first = mm.second = in;
            first = false;
        } else
        {
            if (in.size() < mm.first.size()) mm.first = in;
            if (in.size() > mm.second.size()) mm.second = in;
        }
    }
    std::cout << "Min size = " << mm.first.size() << "in string "<< mm.first << std::endl;
    std::cout << "Max size = " << mm.second.size() << "in string "<< mm.second << std::endl;
    std:
}