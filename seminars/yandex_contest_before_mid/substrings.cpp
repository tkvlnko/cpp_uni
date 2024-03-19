#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

bool comp(const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2)
{
    if (p1.second > p2.second)
    {
        return true;
    }
    else if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return false;
}


int main()
{
    size_t numOfWords, length;
    std::cin >> numOfWords >> length;
    std::map<std::string, int> res;

    for (size_t i = 0; i < numOfWords; i++)
    {
        std::string word;
        std::cin >> word;
        if (length <= word.size())
        {
            // std::cout << word.size() << '\t' << word << '\n';
            // size_t d = word.size() - length;
            // std::cout << typeid(word.length()).name() << '\n';
            for (size_t j = 0; j < word.size() - length + 1; j++)
            {
                std::string substr = word.substr(j, length);
                auto it = res.find(substr);
                if (it == res.end())
                {
                    res.insert({substr, 1});
                }
                else
                {
                    res[substr] += 1;
                }
            }
        }
    }

    std::vector<std::pair<std::string, int>> vec(res.begin(), res.end());
    std::sort(vec.begin(), vec.end(), comp);

    for (const auto& [key, value]: vec)
    {
        std::cout << key << " - " << value << '\n';
    }
}