#pragma once

template <int Row_Size, int Column_Size, class Data_Type, class Column_Type, class Matrix_Type> 
class Matrix_Base  // Matrix: Column_Size x Row_Size, a 4x3 Matrix has 3 column with 4 elements in each column
{
	public:
		Column_Type _[Row_Size] ;
		typedef Data_Type Data_Type;

		inline Column_Type & operator [] ( size_t const& i )			{ return _[i]; }
		inline Column_Type const& operator [] ( size_t const& i ) const	{ return _[i]; }

		inline size_t Row_num () const									{ return Column_Size; }
		inline size_t Column_num () const								{ return Row_Size; }
		inline size_t Row_size () const									{ return Row_Size; }
		inline size_t Column_size () const								{ return Column_Size; }

		inline Matrix_Type operator + (Matrix_Type const& m) const	{
			Matrix_Type rm;
			for (int i = 0; i < Row_size(); i++)
			{
				for (int j = 0; j < Column_size(); j++)
				{
					rm[i][j] = _[i][j];
					rm[i][j] += m[i][j];
				}
			}
			return rm;
		}
		inline Matrix_Type operator - (Matrix_Type const& m) const	{
			Matrix_Type rm;
			for (int i = 0; i < Row_size(); i++)
			{
				for (int j = 0; j < Column_size(); j++)
				{
					rm[i][j] = _[i][j];
					rm[i][j] -= m[i][j];
				}
			}
			return rm;
		}

		inline Matrix_Type operator * (Data_Type const& f) const	{ 
			Matrix_Type rm;
			for (unsigned int i = 0; i < Row_size(); i++)
			{
				for (unsigned int j = 0; j < Column_size(); j++)
				{
					rm[i][j] = _[i][j];
					rm[i][j] *= f;
				}
			}
			return rm;
		
		
		}
		inline Matrix_Type operator / (Data_Type const& f) const	{
		
			Matrix_Type rm;
			for (int i = 0; i < Row_size(); i++)
			{
				for (int j = 0; j < Column_size(); j++)
				{
					rm[i][j] = _[i][j];
					rm[i][j] /= f;
				}
			}
			return rm;
		}
		
		template <int Row_Size, int Column_Size, class Data_Type, class Column_Type, class Matrix_Type>
		friend ostream &operator <<(ostream& output, const Matrix_Base <Row_Size, Column_Size, Data_Type, Column_Type, Matrix_Type> &mat);
} ;
template <int Row_Size, int Column_Size, class Data_Type, class Column_Type, class Matrix_Type>
ostream &operator << (ostream& output, const Matrix_Base <Row_Size, Column_Size, Data_Type,Column_Type ,Matrix_Type> &mat){
	for (int i = 0; i < Row_Size; i++)
	{
		output << "col[" << i << "]: " << mat[i];
	}
	return output;
}