#include "server_Number.h"
#include "common_OSError.h"
#include <string>

Number Number::operator=(int number){
    return Number(number);
}

bool Number::operator==(int number){
    return this->number == number;
}

bool Number::operator==(Number& other){
    return this->number == other.number;
}

bool Number::operator>(int number){
    return this->number > number;
}

bool Number::operator>(Number& other){
    return this->number > other.number;
}

bool Number::operator<(int number){
    return this->number < number;
}

bool Number::operator<(Number& other){
    return this->number < other.number;
}

bool Number::operator>=(int number){
    return this->number >= number;
}

bool Number::operator>=(Number& other){
    return this->number >= other.number;
}

bool Number::operator<=(int number){
    return this->number <= number;
}

bool Number::operator<=(Number& other){
    return this->number <= other.number;
}

Number::operator int () const{
    return this->number;
}

Number::operator uint16_t () const{
    return (uint16_t) this->number;
}

Number::operator uint32_t () const{
    return (uint32_t) this->number;
}


size_t Number::ammountDigits(){
    return (std::to_string(this->number)).size();
} 

bool Number::hasRepeatedDigits(){
    int histogram[10] = {0};
    std::string number = std::to_string(this->number);
    std::string digitString;
    int digit;
    for (size_t i = 0; i < number.size(); i++){
        digitString = number[i];
        digit = std::stoi(digitString);
        histogram[digit]++;
        if (histogram[digit] > 1)
            return true;
    }
    return false;
}

int Number::ammountSameDigitsSamePlace(int number){
    std::string number1 = std::to_string(this->number);
    std::string number2 = std::to_string(number);
    if (number1.size() != number2.size())
        throw OSError("The numbers are of different sizes", 0);
    int sameDigits = 0;
    for (size_t i = 0; i < number1.size(); i++){
        if (number1[i] == number2[i])
            sameDigits++;
    }
    return sameDigits;
}

int Number::ammountSameDigitsSamePlace(Number& other){
    return this->ammountSameDigitsSamePlace(other.number);
}

int Number::ammountSameDigitsDiffPlace(int number){
    std::string number1 = std::to_string(this->number);
    std::string number2 = std::to_string(number);
    if (number1.size() != number2.size())
        throw OSError("The numbers are of different sizes", 0);
    int sameDigits = 0;
    for (size_t i = 0; i < number1.size(); i++){
        for (size_t j = 0; j < number2.size(); j++){
            if (i == j)
                continue;
            if (number1[i] == number2[j])
                sameDigits++;
        }
    }
    return sameDigits;
}

int Number::ammountSameDigitsDiffPlace(Number& other){
    return this->ammountSameDigitsDiffPlace(other.number);
}