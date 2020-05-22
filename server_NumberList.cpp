#include "server_NumberList.h"
#include <fstream>
#include <string>
#include "common_OSError.h"

static bool hasRepeatedDigits(std::string(line)){
    int histogram[10] = {0};
    std::string digitString;
    int digit;
    for (size_t i = 0; i < line.size(); i++){
        digitString = line[i];
        digit = std::stoi(digitString);
        histogram[digit]++;
        if (histogram[digit] > 1)
            return true;
    }
    return false;
}

uint16_t NumberList::parseNumber(std::string line){
    char digit;
    for (int i = 0; i < (int) line.size(); i++){
        digit = line[i];
        if (digit < '0' || digit > '9')
            throw OSError("Error: no se recibio un numero", 0);
    }
    int number = std::stoi(line);
    if (number < 100 || number > 999)
        throw OSError("Error: archivo con numeros fuera de rango", 0);
    if (hasRepeatedDigits(line))
        throw OSError("Error: formato de los numeros invalidos", 0);
    return number;
}

NumberList::NumberList(const char* fileName): index(0){
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line))
        numbers.push_back(parseNumber(line));
}

int NumberList::getNumber(){
    if (index >= numbers.size())
        index = 0;
    return (int) numbers[index++];
}