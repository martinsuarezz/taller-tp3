#ifndef ENCODER_H
#define ENCODER_H
#include <string>
#include <map>
#include <vector>

class Encoder{
    private:
        std::map<std::string, char> map;
        ssize_t stringToULong(std::string number);
        int encodeNumber(size_t number, std::vector<char>& vector);

    public:
        Encoder();
        std::vector<char> encode(std::string command);
};

#endif
