#include "client_Encoder.h"
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "math.h"
#define NUMBER_BYTES 2

Encoder::Encoder(){
    this->map["AYUDA"] = 'h';
    this->map["RENDIRSE"] = 's';
}

int Encoder::encodeNumber(size_t number, std::vector<char>& vector){
    if (number >= (size_t) pow(2, (float) (NUMBER_BYTES * 8)))
        return -1;
    vector.push_back('n');
    char codedNumber[NUMBER_BYTES];
    uint16_t numberNetwork = htons((uint16_t) number);
    memcpy(codedNumber, &numberNetwork, NUMBER_BYTES);
    for (int i = 0; i < NUMBER_BYTES; i++){
        vector.push_back(codedNumber[i]);
    }
    return 0;
}

ssize_t Encoder::stringToULong(std::string number){
    char digit;
    for (int i = 0; i < (int) number.size(); i++){
        digit = number[i];
        if (digit < '0' || digit > '9')
            return -1;
    }
    return std::stoi(number);
}

std::vector<char> Encoder::encode(std::string command){
    std::vector<char> encoded;
    
    try{
        encoded.push_back(map.at(command));
        return encoded;
    }
    catch (std::out_of_range& err){
        ssize_t number;
        if ((number = this->stringToULong(command)) == -1)
            return encoded;
        encodeNumber(number, encoded);
    }

    return encoded;
}