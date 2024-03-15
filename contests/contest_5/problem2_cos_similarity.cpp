#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

void defineSimilatiry(std::string filepath)
{
    std::ifstream inputfile;
    inputfile.open(filepath);
    int numOfWords, dimension;
    std::vector<std::string> similarWords;
    std::string myWord;
    std::vector<int> myWordCoords;
    if (!inputfile.is_open())
    {
        std::cerr << "Cannot open the file: " << filepath << std::endl;
        return;
    }

    std::vector<std::pair<std::string, int>> res;
    int maximum = std::numeric_limits<int>::min();

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
        std::pair<std::string, int> newVec;

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
            sum += (myWordCoords[i] * newWordCoords[i]);
        }

        if (sum > maximum)
        {
            maximum = sum;
        }
        newVec.first = newWord;
        newVec.second = sum;
        res.push_back(newVec);
    }

    for (size_t i = 0; i < res.size(); i++)
    {
        if (res[i].second == maximum)
        {
            std::cout << res[i].first << '\n';
        }
    }
    inputfile.close();
}

int main()
{
    defineSimilatiry("input.txt");
    return 0;
}
