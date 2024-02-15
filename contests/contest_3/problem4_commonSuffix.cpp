#include <iostream>
#include <vector>
#include <string>
#include <cctype>


std::string common_suffix(const std::string& a, const std::string& b) {
    std::string str = "";
    int i1 = a.size() - 1;
    int i2 = b.size() - 1;
    bool f = true;
    while(a[i1] && b[i2] && f) {
        if(a[i1] == b[i2]) {
            str = a[i1] + str;;
            i1--;
            i2--;
        } else {
            f = !f;
            return str;
        }
        
    }
    return str;
}


int main() {
    std::string str1 = "apple";
    std::string str2 = "tuple";

    std::string ss = common_suffix(str1, str2);
    std::cout << ss;

    return 0;
}