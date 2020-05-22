#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <vector>
#include <string>

class NumberList{
    private:
        std::vector<uint16_t> numbers;
        size_t index;
        uint16_t parseNumber(std::string line);

    public:
        NumberList(const char* fileName);
        int getNumber();
};

#endif