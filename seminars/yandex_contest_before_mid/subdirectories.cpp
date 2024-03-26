#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

int main()
{
    std::ifstream inputFile("input.txt");
    std::string line;
    std::vector<std::string> HugeVec;
    std::set<std::string> HugeSet;
    std::vector<std::vector<std::string>> bigVec;
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string data;
        std::vector<std::string> probVec;
        while (std::getline(ss, data, '/'))
        {
            probVec.push_back(data);
        }
        std::vector<std::string> slice(probVec.begin() + 1, probVec.end() - 1);
        bigVec.push_back(slice);
    }
    for (std::vector<std::string> vec: bigVec)
    {
        for (size_t i = 0; i <= vec.size(); ++i)
        {
            std::string x = "";
            for (size_t j = 0; j < i; ++j)
            {
                x += "/" + vec[j];
            }
            if (!x.empty()) HugeSet.insert(x);
        }
    }
    for (auto x: HugeSet)
    {
        HugeVec.push_back(x);
    }

    std::sort(HugeVec.begin(), HugeVec.end());
    if (!HugeVec.empty())
    {
        std::cout << "/" << '\n';
    }
    for (std::string vec: HugeVec) std::cout << vec + "/" << '\n';
}