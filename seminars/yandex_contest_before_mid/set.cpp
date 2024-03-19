#include <fstream>
#include <iostream>
#include <set>

const std::string filepath = "/Users/apple/Desktop/cpp_uni/seminars/yandex_contest_before_mid/input.txt";


// const std::string filepath = "input.txt";
int main()
{
    // std::fstream inputfile(filepath);
    std::set<int> s;
    int a;
    while (std::cin >> a)
    {
        std::set<int>::iterator it = s.find(a);
        if (it != s.end())
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            s.insert(a);
            std::cout << "NO" << std::endl;
        }
    }

    // inputfile.close();
    return 0;
}