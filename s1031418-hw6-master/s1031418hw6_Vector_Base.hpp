#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
template <int Size, class Data_Type, class Vector_Type> 
class Vector_Base	// all vector is column vector
{
	public:
		typedef Data_Type Data_Type;
		Data_Type _[Size] ;
		inline Data_Type & operator [] ( size_t const& i )				{ return _[i]; }
		inline Data_Type const& operator [] ( size_t const& i ) const	{ return _[i]; }
		inline Vector_Type operator - () const 	{
			Vector_Type rv;
			for (size_t i = 0; i < Size; i++)	rv._[i] = -_[i];
			return rv;
		}
		//10pts
		inline Vector_Type operator + ( Vector_Type const& v ) const			{ 
			Vector_Type rv;
			for (int i = 0; i < Size; i++)
			{
				rv[i] = _[i];
				rv[i] += v._[i];
			}
			return rv;
		}
		inline Vector_Type operator - ( Vector_Type const& v ) const			{
			Vector_Type rv;
			for (int i = 0; i < Size; i++)
			{
				rv[i] = _[i];
				rv[i] -= v._[i];
			}
			return rv;
		}
		inline Vector_Type operator * ( Data_Type const& f ) const				{
			Vector_Type rv;
			for (int i = 0; i < Size; i++)
			{
				rv[i] = _[i];
				rv[i] *= f;
			}
			return rv;
		}
		inline Vector_Type operator/ ( Data_Type const& f ) const				{ 
			Vector_Type rv;
			for (int i = 0; i < Size; i++)
			{
				rv[i] = _[i];
				rv[i] /= f;
			}
			return rv;
		}
		template <int Size, class Data_Type, class Vector_Type>
		friend ostream &operator <<(ostream& output, const Vector_Base<Size, Data_Type, Vector_Type> &vec);
} ;
template <int Size, class Data_Type, class Vector_Type>
ostream &operator << (ostream& output, const Vector_Base<Size, Data_Type, Vector_Type> &vec){
	output << "( ";
	output << fixed << setprecision(3);
	for (int i = 0; i < Size; i++)
	{
		output << (i ? ", " : "") << (abs(vec[i])<0.0001 ? 0 : vec[i]);
	}
	output << " )" << endl;
	return output;
}