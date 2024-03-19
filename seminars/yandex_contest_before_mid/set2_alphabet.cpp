#include <fstream>
#include <iostream>
#include <set>
#include <vector>

int main()
{
    std::ifstream inputfile("/Users/apple/Desktop/cpp_uni/seminars/yandex_contest_before_mid/input.txt");
    std::set<std::string> m;
    std::set<char> res;

    size_t min = 10000000;
    std::string minWord = "";

    std::string word;
    while (inputfile >> word)
    {
        // std::cout << word << '\n';

        if (word.size() < min)
        {
            min = word.size();
            minWord = word;
        }
        m.insert(word);
    }


    for (int i = 0; i < min; i++)
    {
        bool flag = true;
        for (const auto& w: m)
        {
            if (w.find(minWord[i]) == std::string::npos)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            res.insert(minWord[i]);
    }

    for (const auto& w: res)
    {
        std::cout << w;
    }
}