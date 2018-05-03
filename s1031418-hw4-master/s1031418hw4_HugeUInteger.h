#ifndef s1031418hw4_HUGE_UINTEGER_H
#define s1031418hw4_HUGE_UINTEGER_H
#include "s1031418hw4_Vector.h"
using namespace std;
#define MAX   //< max length of huge interger
class HugeUInteger 
{
	friend ostream &operator<<(ostream &output, const HugeUInteger &in);
public:
	HugeUInteger(); //< default constructor (the default value = 0)
	HugeUInteger(HugeUInteger &in); //< copy constructor
	HugeUInteger(size_t size);
	~HugeUInteger();

	static HugeUInteger random(size_t size); //< randomly generate an integer, 
	//< the highest digit should not be ZERO

	static HugeUInteger zero(); //< zero this number (size = 1)
	void  divideByTen();
	void  tenfold();
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
	//Vecrtor integer;		//include "PG2Vector.h"
	Vector integer; 	//include <vector>

	//You may add another function here (if necessary)
};

#endif