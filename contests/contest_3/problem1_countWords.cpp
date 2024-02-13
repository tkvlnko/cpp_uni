#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

bool isWord(const std::string& word, size_t& c) {
    bool flag = true;
    for (char elem : word) {
        if (!std::isalpha(elem)) {
            flag = std::ispunct(elem);
        }
        else {
            c++;
        }
    }
    return flag;
}

void countFileStatistics(const std::string& filePath) {
    std::ifstream ifile(filePath);

    size_t l = 0, w = 0, c = 0;
    std::string line;
    while (std::getline(ifile, line)) {
        l++;
        std::replace(line.begin(), line.end(), '-', ' ');
        std::replace(line.begin(), line.end(), '.', ' ');
        std::stringstream ss(line);
        std::cout << line << '\n';

        while (!ss.eof()) {
            std::string word;
            ss >> word;
            if (isWord(word, c)) {
                w++;
            }
        }
    }
    std::cout << l << ' ' << w << ' ' << c;
}

int main() {
    countFileStatistics("/Users/apple/Desktop/cpp_uni/contests/contest_3/data/input.txt");
    return 0;
}