#include "s1031418hw6_Matrix.hpp"

int main ()
{
	// DEMO CODEs, 20pts
	//

	Mat3x4<float> m1 ( Vec3<float> ( 2, 3, 4 ), Vec3<float> ( 1, 5, 7 ), Vec3<float> ( 2, 6, 2 ), Vec3<float> ( 1, 3, 9 ) )  ;
	Mat4x3<float> m2 ( Vec4<float> ( 3, 3, 1, 2 ), Vec4<float> ( 5, 6, 2, 1 ), Vec4<float> ( 9, 3, 0, 8 ) )  ;
	Mat3x3<float> m3 = m1 * m2 ;
	Mat3x3<float> m4(Vec3<float>(3, 3, 3), Vec3<float>(3, 3, 3), Vec3<float>(3, 3, 3));
	//cout << m4.Inverse();//check inverse 
	Mat4x4<float> m5 ( Vec4<float>(3, 0, 1, 2), Vec4<float>(1, 3, 2,1), Vec4<float>(1, 3, 0, 2), Vec4<float>(1, 2, 1, 2 ));
	Mat3x1<float> v1 ( Vec3<float> ( 3, 9, 5 ) ) ;
	Mat3x1<float> v2 = m3 * v1 ;
	Mat3x3<float> m6(Vec3<float>(3, 2, 3), Vec3<float>(2, 4, 5), Vec3<float>(5, 3, 2));
	std::cout << "m1: \n" ; 
	std::cout << m1 << std::endl ;

	std::cout << "m1*2: \n" ; 
	std::cout << m1*2.f << std::endl ;

	std::cout << "m2: \n" ; 
	std::cout << m2 << std::endl ;

	std::cout << "m3 = m1 * m2 ;\nm3: \n" ; 
	std::cout << m3 << std::endl ;

	std::cout << "m3 * m3.Inverse (): \n" ; 
	std::cout << m3 * m3.Inverse () << std::endl ;

	std::cout << "m2.Transpose (): \n" ; 
	std::cout << m2.Transpose () << std::endl ;//

	std::cout << "v1: \n" ; 
	std::cout << v1 << std::endl ;

	std::cout << "v2 = m3 * v1 ;\nv2: \n" ; 
	std::cout << v2 << std::endl ;

	std::cout << "v1.crossProduct (v2): \n" ; 
	std::cout << v1._[0].crossProduct (v2._[0]) << std::endl ;

	std::cout << "v1.dotProduct (v2): \n" ; 
	std::cout << v1._[0].dotProduct(v2._[0]) << std::endl;

	system ("PAUSE") ;
}