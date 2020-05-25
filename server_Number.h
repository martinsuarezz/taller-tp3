#ifndef NUMBER_H
#define NUMBER_H
#include <string>

class Number{
    private:
        int number;
    
    public:
        Number(): number(0) {};
        Number(int number): number(number) {};
        Number operator=(int number);
        bool operator==(int number);
        bool operator==(Number& other);
        bool operator>(int number);
        bool operator>(Number& other);
        bool operator<(int number);
        bool operator<(Number& other);
        bool operator<=(int number);
        bool operator<=(Number& other);
        bool operator>=(int number);
        bool operator>=(Number& other);
        operator int () const;
        operator uint16_t () const;
        operator uint32_t () const;
        size_t ammountDigits();
        bool hasRepeatedDigits();
        int ammountSameDigitsSamePlace(int number);
        int ammountSameDigitsSamePlace(Number& other);
        int ammountSameDigitsDiffPlace(int number);
        int ammountSameDigitsDiffPlace(Number& other);
};

#endif
