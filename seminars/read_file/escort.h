#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>

struct Girl {
    int id, boobs, age, height, size;
    Girl(){

    };
    Girl(int id, int boobs, int age, int height, int size) : id(id), boobs(boobs), age(age), height(height), size(size){};
    bool operator<(const Girl& Lena) const
    {
        return this->id < Lena.id;
    };
};

using Gem = std::map<std::string, std::set<Girl>>;

Gem Reader(const std::string& filePath)
{
    Gem gem;
    std::ifstream inputFile(filePath);
    std::string header;
    std::getline(inputFile, header);
    std::string line;

    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string data;
        Girl Masha;
        for (int i = 0; i < 6; i++)
        {
            std::getline(ss, data, ';');
            // std::cout << data << '\t';
            switch (i)
            {
                case 0:
                    Masha.id = std::stoi(data);
                    break;
                case 1:
                    Masha.age = std::stoi(data);
                    break;
                case 2:
                    Masha.boobs = std::stoi(data);
                    break;
                case 3:
                    Masha.height = std::stoi(data);
                    break;
                case 4:
                    Masha.size = std::stoi(data);
                    break;
                default:
                    // data.erase(std::remove(data.begin(), data.end(), ','), data.end());
                    std::stringstream ssd(data);
                    std::string datum;
                    while (std::getline(ssd, datum, ','))
                    {
                        // std::cout << datum << '\n';
                        Gem::iterator metro = gem.find(datum);
                        if (metro == gem.end())
                        {
                            gem.insert({datum, {Masha}});
                        }
                        else
                        {
                            // metro->second.insert(Masha);
                            gem[datum].insert(Masha);
                        }
                    }
                    // gem.insert()
                    // gem[data] = data;
            }
        }
        // break;
    }
    return gem;
};