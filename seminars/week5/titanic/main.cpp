#include <iostream>
#include <vector>
#include <string>
#include "titanic.h"


const std::string PATH = "/Users/apple/Desktop/cpp_uni/seminars/week5/data/train.csv";

int main() {
    stringMatrix matrix = readCsv(PATH);
    printMatrix(matrix);
    return 0;
}