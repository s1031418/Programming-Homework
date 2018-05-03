//10pts for _Mul
#include <algorithm>
template <class T1, class T2, class T3>
T3 _Mul(T1 const& m1, T2 const& m2)
{
	T3 m3;
	if (m1.Row_size() != m2.Column_size())
		return 0;
	for (int i = 0; i < m3.Row_size(); i++)
	{
		for (int j = 0; j < m1.Column_size(); j++)
		{
			typename T3::Data_Type tmp(0);
			for (int k = 0; k < m1.Row_size(); k++)
				tmp += m1[k][j] * m2[i][k];
			m3[i][j] = tmp;
		}
	}

	return m3;
}

//5pts for _Transpose
template <class T1, class T2>
T2 _Transpose(T1 const& m)
{
	T2 rm;

	for (int i = 0; i < m.Row_size(); i++)
	{
		for (int j = 0; j < m.Column_size(); j++)
		{
			rm[j][i] = m[i][j];
		}
	}
	return rm;
}

//10pts for _Inverse
template <class T0, class T>
T _Inverse(T const& m)
{
	T rm, m0(m);
	T0 tmp;
	for (int i = 0; i < m.Row_size(); i++)
	{
		tmp = m0[i][i];
		for (int j = 0; j < m.Row_size(); j++)
		{
			m0[i][j] /= tmp;
			rm[i][j] /= tmp;
		}
		//cout << m0 << endl;
		for (int j = 0; j < m.Row_size(); j++)
		{
			if (i != j) {
				tmp = m0[j][i];//i是-的行數 j是被-行數
				for (int k = 0; k < m.Row_size(); k++)
				{
					m0[j][k] -= tmp * m0[i][k];//k第幾是元素
					rm[j][k] -= tmp * rm[i][k];//e04他的反矩陣87高斯
				}
			}
		}
	}
	return rm;
}