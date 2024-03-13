#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

void defineSimilatiry(std::string filepath)
{
    std::ifstream inputfile;
    inputfile.open(filepath);
    int numOfWords, dimension;
    std::vector<std::string> similarWords;
    std::string myWord;
    std::vector<int> myWordCoords;
    // std::unordered_map<std::string, int> result;
    std::vector<std::vector<std::string, int>> res;
    int maximum = -100000;

    std::string line1;
    std::getline(inputfile, line1);
    std::stringstream ss1(line1);
    ss1 >> numOfWords >> dimension;

    std::string line2;
    std::getline(inputfile, line2);
    std::stringstream ss2(line2);
    ss2 >> myWord;
    int num;
    while (ss2 >> num)
    {
        myWordCoords.push_back(num);
    }

    std::string line;
    while (!inputfile.eof() && inputfile.good())
    {
        std::vector<int> newWordCoords;
        std::vector<std::string, int> newVec;
        std::getline(inputfile, line);
        std::stringstream ss(line);
        std::string newWord;
        ss >> newWord;
        int c;
        int sum = 0;

        while (ss >> c)
        {
            newWordCoords.push_back(c);
        }

        for (int i = 0; i < dimension; i++)
        {
            // std::cout << myWordCoords[i] << '\t' << newWordCoords[i] << '\n';
            sum += (myWordCoords[i] * newWordCoords[i]);
        }
        // std::cout << sum << '\t';


        if (sum > maximum)
        {
            maximum = sum;
        }
        newVec[0] = newWord;
        newVec[1] = sum;
        res.push_back(newVec);

        // result[newWord] = sum;
    }

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (res[i][j] == maximum)
            {
                std::cout << res[i][j] << '\n';
            }
        }
    }
    // for (const auto& [key, value]: result)
    // {
    //     if (value == maximum)
    //     {
    //         std::cout << key << '\n';
    //     }
    // }
}

int main()
{
    defineSimilatiry("/Users/apple/Desktop/cpp_uni/contests/data/input.txt");
}