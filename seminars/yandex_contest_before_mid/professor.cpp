#include <fstream>
#include <iostream>
#include <map>
#include <set>

int main()
{
    std::fstream inputfile("/Users/apple/Desktop/cpp_uni/seminars/yandex_contest_before_mid/input.txt");
    int numOfWords;
    inputfile >> numOfWords;

    std::map<int, std::set<std::string>> res;

    for (int i = 0; i < numOfWords; i++)
    {
        std::string word;
        int page;
        inputfile >> word >> page;
        auto it = res.find(page);
        if (it == res.end())
        {
            res.insert({page, {word}});
        }
        else
        {
            res[page].insert(word);
        }
    }

    for (auto& [key, value]: res)
    {
        std::cout << key;
        for (auto& word: value)
        {
            std::cout << " " << word;
        }
        std::cout << '\n';
    }
}