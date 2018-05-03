#include"s1031418hw2_HugeUInteger.h"
ostream &operator<<( ostream &output, const HugeUInteger &in )
{
	unsigned int size = in.integer.size();
	if( size == 0 )
		output << 0;
	else
		for( int i = size - 1; i >= 0; i-- )
			output << in.integer[ i ];

	return output; // enables cout << x << y;
}
HugeUInteger::HugeUInteger()
	:integer()
{
}
HugeUInteger::HugeUInteger(HugeUInteger &in)
	:integer(in.integer)
{
}
HugeUInteger HugeUInteger::random(unsigned int size)
{
	HugeUInteger arr;
	arr.integer.resize(size);
	for(unsigned int i=0;i<size;i++)
		arr.integer[i]=rand()%10;
	arr.integer[size-1]=rand()%9+1;
	return arr;
}
HugeUInteger HugeUInteger::zero(){
	HugeUInteger arr;
	arr.integer.resize(1);
	arr.integer[0]=0;
	return arr;
}
HugeUInteger HugeUInteger::operator=(const HugeUInteger &right)
{
	integer=right.integer;
	return *this;
}
bool HugeUInteger::operator==(const HugeUInteger &right){
	if(integer.size()!=right.integer.size())
		return false;
	for(unsigned int i=0;i<integer.size();i++)
		if(integer[i]!=right.integer[i])
			return false;
	return true;
} 
bool HugeUInteger::operator!=(const HugeUInteger &right){
	return !(*this==right);
} //< not equal to
bool HugeUInteger::operator<(const HugeUInteger &right){
	if(integer.size()<right.integer.size())
		return true;
	else if(integer.size()>right.integer.size())
		return false;
	if(integer.size()==right.integer.size())
		for(int i=integer.size()-1;i>=0;i--)
		{
			if(integer[i]>right.integer[i])
				return false;
			if(integer[i]<right.integer[i])
				return true;
		}
}  //< less than
bool HugeUInteger::operator>(const HugeUInteger &right){
	if(integer.size()>right.integer.size())
		return true;
	else if(integer.size()<right.integer.size())
		return false;
	if(integer.size()==right.integer.size()){
		for(int i=integer.size()-1;i>=0;i--){
			if(integer[i]>right.integer[i])
				return true;
			if(integer[i]<right.integer[i])
				return false;
		}
	}
}
HugeUInteger HugeUInteger:: operator+(const HugeUInteger &right){
	int sumsize=(right.integer.size()>=integer.size())? right.integer.size()+1 :integer.size()+1;
	HugeUInteger save;
	save.integer.resize(sumsize);
	for(int i=0;i<integer.size();i++){
		save.integer[i]+=integer[i];
	}
	for(int i=0;i<right.integer.size();i++){
		save.integer[i]+=right.integer[i];
	}
	for(int i=0;i<sumsize;i++){
		if(save.integer[i]>9)
		{
			save.integer[i]=save.integer[i]-10;
			save.integer[i+1]++;
		}
	}
	if(save.integer[sumsize-1]==0)
		save.integer.resize(sumsize-1);
	return save;

}

//< addition operator; HugeUInteger + HugeUInteger
HugeUInteger  HugeUInteger :: operator-(const HugeUInteger &right)
{
	if (*this==right)
	{
		return zero();
	}
	if (*this<right)
	{
		return zero();
	}

	HugeUInteger save;
	save.integer.resize(integer.size());
	for(int i=0;i<integer.size();i++)
	{
		save.integer[i]=integer[i];
	}
	for(int i=0;i<save.integer.size();i++)
	{
		save.integer[i]-=right.integer[i];
		while(save.integer[i]<0)
		{
			save.integer[i]+=10;
			save.integer[i+1]-=1;	
		}
	}
	while(save.integer[save.integer.size()-1]==0&&save.integer.size()>0)
	{
		save.integer.resize(save.integer.size()-1);
	}
	return 	save;
}
//< subtraction operator; HugeUInteger  - HugeUInteger ;
//< (Use ZERO to replace negative result)
HugeUInteger HugeUInteger:: operator*(const HugeUInteger &right){
	if((integer.size()==1&&integer[0]==0)||(right.integer.size()==1&&right.integer[0]==0))
		return zero();

	else
	{
	HugeUInteger save ;
	save.integer.resize(integer.size()+right.integer.size());
	for(int i=0;i<integer.size();i++)
		for(int j=0;j<right.integer.size();j++)
		{
			save.integer[i+j]=save.integer[i+j]+integer[i]*right.integer[j];
		}
	for(int i=0;i<save.integer.size()-1;i++)
		{
			int temp=save.integer[i]/10;
			save.integer[i]%=10;
			save.integer[i+1]+=temp;
		}
		return save;
	}
}

//< multiplication operator; HugeUInteger  * HugeUInteger 
HugeUInteger  HugeUInteger::operator/(const HugeUInteger &right){
//	if(*this <right.integer.size())
		return zero();//i don't know
}
//< division operator; HugeUInteger  / HugeUInteger 
HugeUInteger  HugeUInteger::operator%(const HugeUInteger &right){
	return zero();
}
//< modulus operator; HugeUInteger  % HugeUInteger
///////