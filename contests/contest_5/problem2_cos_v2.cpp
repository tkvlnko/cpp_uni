#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

int main()
{
    std::ifstream inputfile;
    int numOfWords, dimension;
    std::string myWord;
    std::vector<std::pair<std::string, int>> res;
    int maximum = INT_MIN;//🥳

    inputfile.open("/Users/apple/Desktop/cpp_uni/contests/data/input.txt");
    inputfile >> numOfWords >> dimension;// 🤡
    inputfile >> myWord;
    std::vector<int> myWordCoords(dimension);


    for (int i = 0; i < dimension; i++)
    {
        inputfile >> myWordCoords[i];//💀
        // std::cout << myWordCoords[i] << '\n';
    }

    for (int i = 0; i < numOfWords - 1; i++)
    {
        int summ = 0;
        std::pair<std::string, int> newWord;
        inputfile >> newWord.first;

        for (int j = 0; j < dimension; ++j)
        {
            int c;
            inputfile >> c;
            // std::cout << newWord.first << '\t' << c << '\t' << myWordCoords[j] << '\n';
            summ += myWordCoords[j] * c;
            // std::cout << "kjdhf" << '\t' << summ << '\n';
        }
        newWord.second = summ;
        if (summ > maximum)
            maximum = summ;

        res.push_back(newWord);
        // std::cout << newWord.first << '\t' << newWord.second << '\n';
    }

    for (size_t i = 0; i < res.size(); i++)
    {
        if (res[i].second == maximum)
        {
            std::cout << res[i].first << '\n';
        }
    }
    // std::cout << dimension << '\t' << numOfWords << '\t' << myWord << '\n';
}
