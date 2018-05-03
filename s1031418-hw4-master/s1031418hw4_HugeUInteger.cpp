// Member-function definitions for class HugeInteger.
#include "s1031418hw4_HugeUInteger.h" // include definition of class HugeInteger 

// default constructor
HugeUInteger::HugeUInteger()
: integer()
{
}

// default constructor (all digi = 0)
HugeUInteger::HugeUInteger(size_t size)
: integer()
{
	integer.resize(size);
	for (unsigned int i = 0; i < size-1; i++)
		integer[i] = 0;
}

// copy constructor
HugeUInteger::HugeUInteger(HugeUInteger &in)
:integer(in.integer)
{
}
HugeUInteger::~HugeUInteger()
{
	integer.resize(0);
}

// randomly generate an integer
HugeUInteger HugeUInteger::random(size_t size)
{
	HugeUInteger Ans(size);

	Ans.integer[size - 1] = 1 + rand() % 9;
	for (unsigned int i = 0; i < size-1; i++)
		Ans.integer[i] = rand() % 10;

	return Ans;
}

// zero this number (size = 1)
HugeUInteger HugeUInteger::zero()
{
	HugeUInteger Ans(1);
	Ans.integer[0] = 0;

	return Ans;
}
ostream &operator<<(ostream &output, const HugeUInteger &in)
{
	unsigned int size = in.integer.getSize();
	if (size == 0)
		output << 0;
	else //if(!sign) cout << "-";
	for (int i = size - 1; i >= 0; i--)
		output << in.integer[i]; // << " ";

	return output; // enables cout << x << y;
}
HugeUInteger HugeUInteger::operator=(const HugeUInteger &right)
{
	integer = right.integer;
	return *this;
}
bool HugeUInteger::operator==(const HugeUInteger &right){
	if (integer.getSize() != right.integer.getSize())
		return false;
	for (unsigned int i = 0; i<integer.getSize(); i++)
	if (integer[i] != right.integer[i])
		return false;
	return true;
}
bool HugeUInteger::operator!=(const HugeUInteger &right){
	return !(*this == right);
} //< not equal to
bool HugeUInteger::operator<(const HugeUInteger &right){
	if (integer.getSize()<right.integer.getSize())
		return true;
	else if (integer.getSize()>right.integer.getSize())
		return false;
	if (integer.getSize() == right.integer.getSize())
	for (int i = integer.getSize() - 1; i >= 0; i--)
	{
		if (integer[i]>right.integer[i])
			return false;
		if (integer[i]<right.integer[i])
			return true;
	}
}  //< less than
bool HugeUInteger::operator>(const HugeUInteger &right){
	if (integer.getSize()>right.integer.getSize())
		return true;
	else if (integer.getSize()<right.integer.getSize())
		return false;
	if (integer.getSize() == right.integer.getSize()){
		for (int i = integer.getSize() - 1; i >= 0; i--){
			if (integer[i]>right.integer[i])
				return true;
			if (integer[i]<right.integer[i])
				return false;
		}
	}
}
HugeUInteger HugeUInteger::operator+(const HugeUInteger &right){
	int sumsize = (right.integer.getSize() >= integer.getSize()) ? right.integer.getSize() + 1 : integer.getSize() + 1;
	HugeUInteger save;
	save.integer.resize(sumsize);
	for (int i = 0; i<integer.getSize(); i++){
		save.integer[i] += integer[i];
	}
	for (int i = 0; i<right.integer.getSize(); i++){
		save.integer[i] += right.integer[i];
	}
	for (int i = 0; i<sumsize; i++){
		if (save.integer[i]>9)
		{
			save.integer[i] = save.integer[i] - 10;
			save.integer[i + 1]++;
		}
	}
	if (save.integer[sumsize - 1] == 0)
		save.integer.resize(sumsize - 1);
	return save;
}
//< addition operator; HugeUInteger + HugeUInteger
HugeUInteger  HugeUInteger::operator - (const HugeUInteger &right){
	if (*this == right)
	{
		return zero();
	}
	if (*this<right)
	{
		return zero();
	}
	else
	{
		HugeUInteger save;
		save.integer.resize(integer.getSize());
		for (int i = 0; i < save.integer.getSize(); i++)
		{
			save.integer[i] = 0;
		}
		for (int i = 0; i < save.integer.getSize() ; i++)
		{
			save.integer[i] = integer[i];
		}
		for (int i = 0; i < right.integer.getSize(); i++)//use right to sub then no err(or right will overflow)
		{
			save.integer[i] -= right.integer[i];
			while (save.integer[i]<0)
			{
				save.integer[i] += 10;
				save.integer[i + 1] -= 1;
			}
		}
		for (int i = 0; i<save.integer.getSize(); i++)
		{
			if (save.integer[i]>9)
			{
				save.integer[i] -= 10;
				save.integer[i + 1] += 1;
			}
		}
		while (save.integer[save.integer.getSize() - 1] == 0 && save.integer.getSize()>0)
		{
			save.integer.resize(save.integer.getSize() - 1);
		}
		return 	save;
	}
}
//< subtraction operator; HugeUInteger  - HugeUInteger ;
//< (Use ZERO to replace negative result)
HugeUInteger HugeUInteger::operator*(const HugeUInteger &right){
	if ((integer.getSize() == 1 && integer[0] == 0) || (right.integer.getSize() == 1 && right.integer[0] == 0))
		return zero();	
	else
	{
		HugeUInteger save; 
		save.integer.resize(integer.getSize() + right.integer.getSize());
		for (int i = 0; i<integer.getSize(); i++)   
		for (int j = 0; j<right.integer.getSize(); j++)
		{
			save.integer[i + j] = save.integer[i + j] + integer[i] * right.integer[j];
		}
		for (int i = 0; i<save.integer.getSize() - 1; i++)
		{
			int temp = save.integer[i] / 10;
			save.integer[i] %= 10;
			save.integer[i + 1] += temp;
		}
		while (save.integer[save.integer.getSize() - 1] == 0 && save.integer.getSize()>0)
		{
			save.integer.resize(save.integer.getSize() - 1);
		}
		return save;
	}
}
HugeUInteger HugeUInteger::operator/(const HugeUInteger &right){
	HugeUInteger aidOp;//aidOp copy right 
	HugeUInteger  remainder, quotient; //remainder copy this  quotinet max size=this+right-1;
	if (*this<right)
		return zero();
	aidOp.integer.resize(right.integer.getSize());
	for (int i = 0; i < right.integer.getSize(); i++)
		aidOp.integer[i] = right.integer[i];
	remainder.integer.resize(integer.getSize());
	for (int i = 0; i < integer.getSize(); i++)
		remainder.integer[i] = integer[i];
	quotient.integer.resize(integer.getSize()-right.integer.getSize()+1);
	quotient.integer[0] = 0;
	while (*this > aidOp||*this==aidOp)
		aidOp.tenfold(); //(until it < this )
	aidOp.divideByTen();  // if 12345/11  12345>11 12345>110 12345>1100 12345>11000(use this) 12345<110000
	while (remainder > right ||remainder==right)
	{
		while (remainder > aidOp ||remainder==aidOp)
		{
			remainder = remainder - aidOp; //12345-11000 
			(*(quotient.integer.begin()))++; //quo=1 (when every sub begin ++) (begin>right hand)
		}
		quotient.tenfold(); //when aidOp > remain (11000>1345)
		aidOp.divideByTen(); //aidOp/10 then 1100 will <1345 until <right (11);
	}

	quotient.divideByTen(); // cause the lase (remainder > right) quo will *10 so we /10 it will be correct;
	while (quotient.integer[quotient.integer.getSize() - 1] == 0 && quotient.integer.getSize()>0)
	{
		quotient.integer.resize(quotient.integer.getSize() - 1);
	}//check the left if = 0 ;
	
	return quotient;

}
HugeUInteger HugeUInteger::operator%(const HugeUInteger &right){
	return *this - (*this / right)*right;
}
void HugeUInteger::divideByTen() // /10 used by /
{
	for (int i = 1; i < integer.getSize(); i++)
		integer[i - 1] = integer[i];
	integer[integer.getSize()-1] = 0;
	integer.resize(integer.getSize()-1);
} 
void HugeUInteger::tenfold() // *10 used by /
{
	integer.resize(integer.getSize()+1);
	for (int i = integer.getSize()-1;i>0; i--)
		integer[i] = integer[i-1];
	integer[0] = 0;
} 