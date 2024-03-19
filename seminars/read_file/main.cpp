#include "escort.h"
#include <iostream>

const std::string filePath = "/Users/apple/Desktop/cpp_uni/seminars/read_file/data/escort.csv";

int main()
{
    Gem gemchik = Reader(filePath);
    for (std::pair<std::string, std::set<Girl>> gemGemych: gemchik)
    {
        std::cout << gemGemych.first << '\n';
    }
}