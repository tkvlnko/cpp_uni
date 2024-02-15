#include <iostream>
#include <vector>
#include <string>
#include <cctype>


std::string ExtractDigits(const std::string& s) {
    std::string str = "";
    for (size_t i = 0; i < s.size(); i++) {
        if (std::isdigit(s[i])) {
            str += s[i];
        }
    }
    return str;
}


int main() {
    std::string str = "2+2=4";
    std::cout << ExtractDigits(str) << "\n";
    return 0;
}