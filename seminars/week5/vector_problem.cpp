#include <iostream>
#include <vector>
#include <string>


std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string res;
    if (tokens.size() == 0)
        return res;
    for (int i = 0; i < tokens.size() - 1; i++) 
        res+= tokens[i] + delimiter;
    return res + *(tokens.end() - 1);
}

int main() {
    std::vector<std::string> vec {"kjh", "kjh"};
    std::cout << join(vec, '-');
    return 0;
}