#pragma once

#include "s1031418hw6_Vector_Base.hpp"

template <class T> 
class Vec1 : public Vector_Base <1, T, Vec1<T>>
{
	public:
		inline Vec1 ( T const& x = 0 )									{ _[0] = x; }
} ;

template <class T> 
class Vec2 : public Vector_Base <2, T, Vec2<T>>
{
	public:
		inline Vec2 ( T const& x = 0, T const& y = 0 )					{ _[0] = x; _[1] = y; }

		inline T dotProduct ( Vec2<T> const& v )						{ return ( _[0]*v._[0] + _[1]*v._[1] ); }
} ;


template <class T> //10pts
class Vec3 : public Vector_Base <3, T, Vec3<T>>
{
	public:
		inline Vec3<T> ( T const& x=0,T const& y=0, T const& z=0)	{ _[0] = x; _[1] = y; _[2] = z; }
		inline Vec3<T> crossProduct(Vec3<T> const& v)	{
			return Vec3<T>((_[1] * v._[2] - _[2] * v._[1]),(_[2] * v._[0] - _[0] * v._[2]),(_[0] * v._[1] - _[1] * v._[0]));
		}
		inline T dotProduct(Vec3<T> const& v)			{
			return(_[0] * v._[0] + _[1] * v._[1] + _[2] * v._[2]);
		}
} ;
 
template <class T> //10pts
class Vec4 : public Vector_Base <4, T, Vec4<T>>
{
public:
	inline Vec4(T const& x = 0, T const& y = 0, T const& z = 0, T const&k = 0)	{ _[0] = x; _[1] = y; _[2] = z; _[3] = k; }
	inline T dotProduct(Vec4<T>const&v)
	{
		return(_[0] * v._[0] + _[1] * v._[1] + _[2] * v._[2] + _[3] * v._[3]);
	}
} ;