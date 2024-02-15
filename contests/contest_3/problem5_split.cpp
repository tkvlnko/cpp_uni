#include <iostream>
#include <vector>
#include <string>
#include <sstream>


std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> res;
    std::stringstream ss(str);
    std::string word;


    while (std::getline(ss, word, delimiter)) {
        res.push_back(word);
    }

    if (str[str.size() - 1] == delimiter) {
        res.push_back("");
    }
    return res;
}


int main() {
    std::string str = "-13-24--08-11-2014-";
    std::vector<std::string> vec =  split(str, '-');
    for (const auto& s : vec) {
        std::cout << s << "\n";
    }
    return 0;
}