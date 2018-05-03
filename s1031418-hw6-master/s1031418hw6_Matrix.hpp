#pragma once

#include "s1031418hw6_Vector.hpp"
#include "s1031418hw6_Matrix_Base.hpp"

//6pts for each template class (total 30pts), 
////Constructor: 2pts, operator*: 4pts
template <class T> class Mat1x1 ;
template <class T> class Mat1x3 ;
template <class T> class Mat1x4 ;
template <class T> class Mat3x1 ;
template <class T> class Mat4x1 ;
template <class T> class Mat3x3 ;
template <class T> class Mat3x4 ;
template <class T> class Mat4x3 ;
template <class T> class Mat4x4 ;

template <class T1, class T2, class T3> T3 _Mul ( T1 const& m1, T2 const& m2 ) ;
template <class T1, class T2> T2 _Transpose ( T1 const& m ) ;
template <class T0, class T> T _Inverse ( T const& m_ ) ;

template <class T> class Mat1x1 : public Matrix_Base<1, 1, T, Vec1<T>, Mat1x1<T>>
{
	public:
		inline Mat1x1 ( Vec1<T> const& _0 )								{ _[0] = _0; }

		inline Mat1x1 Transpose () const								{ return _Transpose<Mat1x1, Mat1x1> (*this); }
		inline Mat1x3<T> operator * ( Mat1x3<T> const& m ) const		{ return _Mul<Mat1x1, Mat1x3<T>, Mat1x3<T>> ( *this, m ); }
		inline Mat1x4<T> operator * ( Mat1x4<T> const& m ) const		{ return _Mul<Mat1x1, Mat1x4<T>, Mat1x4<T>> ( *this, m ); }	//add it back when Mat1x4 is ready
		inline Mat1x1 operator * ( Mat1x1 const& m ) const				{ return _Mul<Mat1x1, Mat1x1, Mat1x1> ( *this, m ); }

		using Matrix_Base<1, 1, T, Vec1<T>, Mat1x1<T>>::operator * ;
} ;

template <class T> class Mat1x3 : public Matrix_Base<3, 1, T, Vec1<T>, Mat1x3<T>>
{
	public:
		inline Mat1x3 ( Vec1<T> const& _0 = Vec1<T> ( 0 ), Vec1<T> const& _1 = Vec1<T> ( 0 ), Vec1<T> const& _2 = Vec1<T> ( 0 ) )		
																		{ _[0] = _0; _[1] = _1; _[2] = _2; }
		inline Mat1x4<T> operator *() const								{ return _Transpose<Mat1x3, Mat3x4<T>, Mat1x4<T>>>(*this); }

		inline Mat3x1<T> Transpose () const								{ return _Transpose<Mat1x3, Mat3x1<T>> (*this); }
		inline Mat1x1<T> operator * ( Mat3x1<T> const& m ) const		{ return _Mul<Mat1x3, Mat3x1<T>, Mat1x1<T>> ( *this, m ); }
		inline Mat1x3 operator * ( Mat3x3<T> const& m ) const			{ return _Mul<Mat1x3, Mat3x3<T>, Mat1x3> ( *this, m ); }

		using Matrix_Base<3, 1, T, Vec1<T>, Mat1x3<T>>::operator * ;
} ;

template <class T> class Mat1x4 : public Matrix_Base<4, 1, T, Vec1<T>, Mat1x4<T>>
{
public:
	inline Mat1x4(Vec1<T> const& _0 = Vec1<T>(0), Vec1<T> const& _1 = Vec1<T>(0), Vec1<T> const& _2 = Vec1<T>(0),Vec1<T>const&_3=Vec1<T>(0))
	{
		_[0] = _0; _[1] = _1; _[2] = _2; _[3] = _3;
	}

	inline Mat4x1<T> Transpose() const								{ return _Transpose<Mat1x4, Mat4x1<T>>(*this); }
	inline Mat1x1<T> operator * (Mat4x1<T> const& m) const		{ return _Mul<Mat1x4, Mat4x1<T>, Mat1x1<T>>(*this, m); }
	inline Mat1x4 operator * (Mat4x4<T> const& m) const			{ return _Mul<Mat1x4, Mat4x4<T>, Mat1x4>(*this, m); }
	inline Mat1x3 operator * (Mat4x3<T> const& m) const			{ return _Mul<Mat1x4, Mat4x3<T>, Mat1x3>(*this, m); }

		using Matrix_Base<4, 1, T, Vec1<T>, Mat1x4<T>>::operator *;
} ;
template <class T> class Mat3x1 : public Matrix_Base<1, 3, T, Vec3<T>, Mat3x1<T>>
{
	public:
		inline Mat3x1(Vec3<T> const& _0 = Vec3<T>(0, 0, 0))		{ _[0] = _0; }
		inline Mat3x4<T> operator * (Mat1x4<T> const& m) const		{ return _Mul<Mat3x3, Mat3x4<T>, Mat3x4<T>>(*this, m); }
		inline Mat1x3<T> Transpose() const							{ return _Transpose<Mat3x1, Mat1x3<T>>(*this); }
		inline Mat3x3<T> operator * (Mat1x3<T> const& m) const		{ return _Mul<Mat3x1, Mat1x3<T>, Mat3x3<T>>(*this, m); }
		inline Mat3x1 operator * (Mat1x1<T> const& m) const			{ return _Mul<Mat3x1, Mat1x1<T>, Mat3x1>(*this, m); }
		using Matrix_Base<1, 3, T, Vec3<T>, Mat3x1<T>>::operator *;
} ;

template <class T> class Mat4x1 : public Matrix_Base<1, 4, T, Vec4<T>, Mat4x1<T>>
{
public:
	inline Mat4x1(Vec4<T> const& _0 = Vec4<T>(0, 0, 0,0))		{ _[0] = _0; }
	inline Mat4x3<T> operator * (Mat1x3<T> const& m) const		{ return _Mul<Mat4x1, Mat1x3<T>, Mat4x3<T>>(*this, m); }
	inline Mat1x4<T> Transpose() const							{ return _Transpose<Mat4x1, Mat1x4<T>>(*this); }
	inline Mat4x4<T> operator * (Mat1x4<T> const& m) const		{ return _Mul<Mat4x1, Mat1x4<T>, Mat4x4<T>>(*this, m); }
	inline Mat4x1 operator * (Mat1x1<T> const& m) const			{ return _Mul<Mat4x1, Mat1x1<T>, Mat4x1>(*this, m); }
	using Matrix_Base<1, 4, T, Vec4<T>, Mat4x1<T>>::operator *;
} ;

template <class T> class Mat3x3 : public Matrix_Base<3, 3, T, Vec3<T>, Mat3x3<T>>
{
	public:
		inline Mat3x3 ( Vec3<T> const& _0 = Vec3<T> ( 1, 0, 0 ), Vec3<T> const& _1 = Vec3<T> ( 0, 1, 0 ), Vec3<T> const& _2 = Vec3<T> ( 0, 0, 1 ) )	
																		{ _[0] = _0; _[1] = _1; _[2] = _2; }
		inline Mat3x3 Transpose () const								{ return _Transpose<Mat3x3, Mat3x3> (*this); }
		inline Mat3x3 Inverse () const									{ return _Inverse<T, Mat3x3> (*this); }
		inline Mat3x3 operator * ( Mat3x3 const& m ) const				{ return _Mul<Mat3x3, Mat3x3, Mat3x3> ( *this, m ); }
		inline Mat3x4<T> operator * ( Mat3x4<T> const& m ) const		{ return _Mul<Mat3x3, Mat3x4<T>, Mat3x4<T>> ( *this, m ); }
		inline Mat3x1<T> operator * ( Mat3x1<T> const& m ) const		{ return _Mul<Mat3x3, Mat3x1<T>, Mat3x1<T>> ( *this, m ); }
		using Matrix_Base<3, 3, T, Vec3<T>, Mat3x3<T>>::operator * ;
} ;

template <class T> class Mat3x4 : public Matrix_Base<4, 3, T, Vec3<T>, Mat3x4<T>>
{
public:
	inline Mat3x4(Vec3<T> const& _0 = Vec3<T>(1, 0, 0), Vec3<T> const& _1 = Vec3<T>(0, 1, 0), Vec3<T> const& _2 = Vec3<T>(0, 0, 1),Vec3<T> const&_3 =Vec3<T>(1,1,1))
	{
		_[0] = _0; _[1] = _1; _[2] = _2; _[3] =_3;
	}
	inline Mat4x3<T> Transpose() const								{ return _Transpose<Mat3x4, Mat4x3<T>>(*this); }
	inline Mat3x4 Inverse() const									{ return _Inverse<T, Mat3x4>(*this); }
	using Matrix_Base<4, 3, T, Vec3<T>, Mat3x4<T>>::operator *;
	inline Mat3x3<T> operator * (Mat4x3<T> const&m)const { return _Mul<Mat3x4, Mat4x3<T>, Mat3x3<T>>(*this, m); }
	inline Mat3x1<T> operator *(Mat4x1<T>const&m)const { return _Mul<Mat3x4, Mat4x1<T>, Mat3x1<T>>(*this, m); }
	inline Mat4x4<T> operator * (Mat4x4<T> const& m) const		{ return _Mul<Mat3x4, Mat4x4<T>, Mat4x4<T>>(*this, m); }
} ;
template <class T> class Mat4x3 : public Matrix_Base<3, 4, T, Vec4<T>, Mat4x3<T>>
{
public:
	using Matrix_Base<3, 4, T, Vec4<T>, Mat4x3<T>>::operator *;

	inline Mat4x3(Vec4<T> const& _0 = Vec4<T>(1, 0, 0), Vec4<T> const& _1 = Vec4<T>(0, 1, 0), Vec4<T> const& _2 = Vec4<T>(0, 0, 0))
	{
		_[0] = _0; _[1] = _1; _[2] = _2;
	}
	inline Mat3x4<T> Transpose() const								{ return _Transpose<Mat4x3,Mat3x4<T>>(*this); }
	inline Mat4x4<T> operator * (Mat3x4<T> const&m)const { return _Mul<Mat4x3, Mat3x4<T>, Mat4x4<T>>(*this, m); }
	inline Mat4x1<T> operator * (Mat3x1<T> const&m)const { return _Mul<Mat4x3, Mat3x1<T>, Mat4x1<T>>(*this, m); }
	inline Mat4x3<T> operator * (Mat3x3<T> const& m) const		{ return _Mul<Mat4x3, Mat3x3<T>, Mat4x3<T>>(*this, m); }
	
};

template <class T> class Mat4x4 : public Matrix_Base<4, 4, T, Vec4<T>, Mat4x4<T>>
{
public:
	inline Mat4x4(Vec4<T> const& _0 = Vec4<T>(1, 0, 0,0), Vec4<T> const& _1 = Vec4<T>(0, 1, 0,0), Vec4<T> const& _2 = Vec4<T>(0, 0, 1, 0),Vec4<T> const& _3 = Vec4<T>(0,0,0,1))
	{
		_[0] = _0; _[1] = _1; _[2] = _2; _[3] = _3;
	}
	inline Mat4x4<T> Transpose() const								{ return _Transpose<Mat4x4, Mat4x4<T>>(*this); }
	inline Mat4x1<T> operator * (Mat4x1<T> const&m)const { return _Mul<Mat4x4, Mat4x1<T>, Mat4x1<T>>(*this, m); }
	inline Mat4x3<T> operator * (Mat4x3<T> const&m)const { return _Mul<Mat4x4, Mat4x3<T>, Mat4x3<T>>(*this, m); }
	using Matrix_Base<4, 4, T, Vec4<T>, Mat4x4<T>>::operator *;
	inline Mat4x4 Inverse() const									{ return _Inverse<T, Mat4x4>(*this); }
	inline Mat4x4<T> operator * (Mat4x4<T> const&m)const { return _Mul<Mat4x4, Mat4x4<T>, Mat4x4<T>>(*this, m); }

} ;
#include "s1031418hw6_Matrix.inl"
