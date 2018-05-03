#ifndef s1031418hw2_HUGEUINTEGER_H
#define s1031418hw2_HUGEUINTEGER_H
#include <fstream>
#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000 //< max length of huge interger
class HugeUInteger 
{
    friend ostream &operator<<(ostream &output, const HugeUInteger &in);

public:
    HugeUInteger(); //< default constructor (the default value = 0)
    HugeUInteger(HugeUInteger &in); //< copy consstructor
    static HugeUInteger random(unsigned int size); //< randomly generate an integer, 
                                                   //< the highest digit should not be ZERO
    static HugeUInteger zero(); //< generate a zero number (size = 1)
    HugeUInteger operator=(const HugeUInteger &right); //< assignment
    bool operator==(const HugeUInteger &right); //< equal to
    bool operator!=(const HugeUInteger &right); //< not equal to
    bool operator<(const HugeUInteger &right);  //< less than
    bool operator>(const HugeUInteger &right);  //< greater than
	
    HugeUInteger operator+(const HugeUInteger &right);
    //< addition operator; HugeUInteger + HugeUInteger
   HugeUInteger  operator-(const HugeUInteger &right);
    //< subtraction operator; HugeUInteger  - HugeUInteger ;
    //< (Use ZERO to replace negative result)
   HugeUInteger  operator*(const HugeUInteger &right);
    //< multiplication operator; HugeUInteger  * HugeUInteger 
   HugeUInteger  operator/(const HugeUInteger &right);
    //< division operator; HugeUInteger  / HugeUInteger 
   HugeUInteger  operator%(const HugeUInteger &right);
    //< modulus operator; HugeUInteger  % HugeUInteger
private:
///add something to stores a huge integer (dynamic array or std::vector or ¡K)
///add some helper functions
	vector<int> integer;//
};
#endif;