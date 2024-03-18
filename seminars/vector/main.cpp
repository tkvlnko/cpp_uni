#include "vector.hpp"
#include <iostream>

int main()
{
    notstd::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    v.push_back(10);
    v.push_back(11);

    // std::cout << v[0];
    v[4] = 20;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << '\n';
    }
}