#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>

bool isWord(const std::string& word, size_t* c) {
    if (word.empty()) {
        return false;
    }
    bool flag = true;
    for (char elem : word) {
        if (!std::isalpha(elem))
            flag = std::ispunct(elem);
        else
            (*c)++;
    }
    return flag;
}

void countFileStatistics(const std::string& filePath, size_t* c, size_t* w, size_t* l) {
    std::ifstream ifile(filePath);

    std::string line;
    while (std::getline(ifile, line)) {
        (*l)++;
        std::replace(line.begin(), line.end(), '-', ' ');
        std::replace(line.begin(), line.end(), '\'', ' ');
        std::replace(line.begin(), line.end(), '.', ' ');
        std::stringstream ss(line);

        while (!ss.eof()) {
            std::string word;
            ss >> word;
            if (isWord(word, c)) {
                (*w)++;
            }
        }
    }
}

int main() {
    size_t c = 0, w = 0, l = 0;
    // std::string filepath;
    // std::cin >> filepath;
    countFileStatistics("/Users/apple/Desktop/cpp_uni/contests/contest_3/data/input.txt", &c, &w, &l);
    std::cout << "Input file contains:" << '\n' <<
    c << " letters" << '\n' <<
    w << " words" << '\n' <<
    l << " lines";
    return 0;
}