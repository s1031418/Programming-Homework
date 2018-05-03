#include "s1031418hw5_Shape.h"
namespace MIME{
	Vertex Vertex::operator-(const Vertex &right){
		Vertex vector;
		vector.x = x - right.x;
		vector.y = y - right.y;
		return vector;
	}
	double Vertex::operator*(const Vertex &right)
	{
		double ans;
		ans = 0.5*abs(x*right.y-y*right.x);
		return ans;
	}
	bool Vertex::operator==(const Vertex &right)
	{
		if (x == right.x&&y == right.y)
			return true;
		else
			return false;
	}
	double Vertex::dotproduct(const Vertex &point1, const Vertex &point2)
	{
		Vertex Vector;
		Vector.x = point1.x - x;
		Vector.y = point1.y - y;
		Vertex Vector2;
		Vector2.x = point2.x - x;
		Vector2.y = point2.y - y;
		return (Vector.x*Vector2.x) + (Vector.y*Vector2.y);
	}
	double Vertex::len(const Vertex &right)
	{
		double len;
		len = sqrt((right.x - x)*(right.x - x) + (right.y - y)*(right.y - y));
		return len;
	}
	double Vertex::vectorproportion(const Vertex &right)
	{
		return(right.x - x) / (right.y-y);
	}
	double Vertex::verconvex(const Vertex &vector){
		return ((x*vector.y) - (y*vector.x));
	}
	void Shape::print()
	{
		std::cout << "TYPE: " << outputName[CurrentType] << std::endl;
		for (int i = 0; i < vertices.size(); i++)
		{
			vertices[i].print();
			std::cout << std::endl;
		}
	}
	ShapeType Shape::getType(){
		return CurrentType;
	}

	bool Shape::isConvex()
	{
		if (!isValid())
			return false;
		double arr[100];
		std::vector<Vertex>convex(vertices);
		convex.push_back(vertices[0]);
		convex.push_back(vertices[1]);
		for (int i = 0; i < convex.size()-2; i++)
		{
			arr[i] = (convex[i] - convex[i + 1]).verconvex(convex[i + 1] - convex[i + 2]);
		}
		for (int i = 0; i < convex.size(); i++)
		{
			if (arr[i] < 0)
			{
				if (arr[i+1]>0)
					return false;
			}
			else if (arr[i]>0)
			{
				if (arr[i + 1] < 0)
					return false;
			}
		}
		return true;
	}
	double Triangle::getArea()
	{
		if (isValid())
			return (vertices[1] - vertices[0])*(vertices[2] - vertices[0]);
		else
			return -1;
	}
	bool Triangle::isValid()
	{
		if (vertices.size() == 3)
		{
			double arr[100];
			std::vector<Vertex>convex(vertices);
			convex.push_back(vertices[0]);
			convex.push_back(vertices[1]);
			for (int i = 0; i < convex.size() - 2; i++)
			{
				arr[i] = (convex[i] - convex[i + 1]).verconvex(convex[i + 1] - convex[i + 2]);
			}
			for (int i = 0; i < convex.size(); i++)
			{
				if (abs(arr[i]) < 0.0000000001)
					return false;
			}
			return true;
		}
		else
			return false;
	}
	bool Isosceles_Triangle::isValid()
	{
		if ((vertices[0].len(vertices[1]) - vertices[0].len(vertices[2])) < 0.00001 || abs(vertices[1].len(vertices[2]) - vertices[2].len(vertices[0])) < 0.00000001 || abs(vertices[1].len(vertices[0]) - vertices[1].len(vertices[2])) < 0.00001)
				return true;
		else
			return false;
	}
	double Isosceles_Triangle::getArea()
	{
		if (isValid())
		{
			if (vertices[0].len(vertices[1]) == vertices[1].len(vertices[2]))
			{
				double hight;
				hight = (vertices[0].len(vertices[1])*vertices[0].len(vertices[1])) - (vertices[0].len(vertices[2]) / 2)*(vertices[0].len(vertices[2]) / 2);
				hight = sqrt(hight);
				return hight*vertices[0].len(vertices[2]) / 2;
			}
			else if (vertices[0].len(vertices[2]) == vertices[1].len(vertices[2]))
			{
				double hight;
				hight = (vertices[2].len(vertices[1])*vertices[2].len(vertices[1])) - (vertices[0].len(vertices[1]) / 2)*(vertices[0].len(vertices[1]) / 2);
				hight = sqrt(hight);
				return hight*vertices[0].len(vertices[1]) / 2;
			}
			else if (vertices[0].len(vertices[2]) == vertices[1].len(vertices[0]))
			{
				double hight;
				hight = (vertices[0].len(vertices[1])*vertices[0].len(vertices[1])) - (vertices[2].len(vertices[1]) / 2)*(vertices[2].len(vertices[1]) / 2);
				hight = sqrt(hight);
				return hight*vertices[2].len(vertices[1]) / 2;
			}
		}
		else
			return -1;
	}
	double Regular_Triangle::getArea()
	{
		if (isValid())
		{
			double p = vertices[0].len(vertices[1]) + vertices[0].len(vertices[2]) + vertices[1].len(vertices[2]);
			p = p / 2;
			return sqrt(p*(p - vertices[0].len(vertices[1]))*(p - vertices[0].len(vertices[2]))*(p - vertices[1].len(vertices[2])));
		}
		else
			return -1;
	}
	bool Regular_Triangle::isValid()
	{
		double zerotoone;
		zerotoone = vertices[0].len(vertices[1]);
		double onetotwo;
		onetotwo = vertices[1].len(vertices[2]);
		double twotozero;
		twotozero = vertices[2].len(vertices[0]);
		if (abs(zerotoone - onetotwo) < 0.001&&abs(zerotoone - twotozero) < 0.001)
			return true;
		else
			return false;

	}
	bool Right_triangle::isValid()
	{
		if (abs(vertices[0].dotproduct(vertices[1],vertices[2])) < 0.000001 || abs(vertices[1].dotproduct(vertices[2],vertices[0]))<0.000001 || abs(vertices[2].dotproduct(vertices[0],vertices[1]))<0.0000001)
			return true;
		else
			return false;
	}
	double Right_triangle::getArea()
	{
		if (isValid())
		{
			if (abs(vertices[0].dotproduct(vertices[1], vertices[2])) <0.000001){
				return (vertices[0].len(vertices[1]))*(vertices[0].len(vertices[2]))/2;
			}
			else if (abs(vertices[1].dotproduct(vertices[2], vertices[0]))< 0.00001)
			{
				return (vertices[1].len(vertices[0]))*(vertices[1].len(vertices[2]))/2;
			}
			else if (abs(vertices[2].dotproduct(vertices[0], vertices[1])) <0.000001)
			{
				return (vertices[2].len(vertices[0]))*(vertices[2].len(vertices[1]))/2;

			}
		}
		else
			return -1;
	}
	double Quadrilateral::getArea()
	{
		if (isValid())
			return (vertices[1] - vertices[0])*(vertices[2] - vertices[0]) + (vertices[2] - vertices[0])*(vertices[3] - vertices[0]);
		else
			return -1;
	}
	bool Quadrilateral::isValid()
	{
		if (vertices.size() == 4){

			double arr[100];
			std::vector<Vertex>convex(vertices);
			convex.push_back(vertices[0]);
			convex.push_back(vertices[1]);
			for (int i = 0; i < convex.size() - 2; i++)
			{
				arr[i] = (convex[i] - convex[i + 1]).verconvex(convex[i + 1] - convex[i + 2]);
			}
			for (int i = 0; i < convex.size(); i++)
			{
				if (abs(arr[i]) < 0.0000000001)
					return false;
			}
			return true;
		}
		else
			return false;
	}
	bool Parallelogrm::isValid()
	{
		if (((vertices[0] - vertices[1]) == (vertices[3] - vertices[2])) && ((vertices[2] - vertices[1]) == (vertices[3] - vertices[0])))
			return true;
		else
			return false;
	}
	double Parallelogrm::getArea()
	{
		if (isValid())
		{
			double cos;
			cos = vertices[0].dotproduct(vertices[1], vertices[3]) / vertices[0].len(vertices[1])*vertices[0].len(vertices[3]);
			double sin;
			sin = sqrt(1 - cos*cos);
			return vertices[0].len(vertices[1])*vertices[0].len(vertices[3])*sin;//0-1 * 0-3 *sin 
		}
		else
			return -1;
	}
	double Square::getArea()
	{
		if (isValid())
			return vertices[0].len(vertices[1])*vertices[0].len(vertices[1]);
		else
			return -1;
	}
	bool Square::isValid()
	{
		if (abs(vertices[0].dotproduct(vertices[1], vertices[3])) < 0.00001&&abs(vertices[1].dotproduct(vertices[0], vertices[2])) < 0.00001&&abs(vertices[2].dotproduct(vertices[1], vertices[3])) < 0.0000001&&abs(vertices[3].dotproduct(vertices[2], vertices[0])) < 0.00001)
		{
			if (abs(vertices[0].len(vertices[1])-vertices[2].len(vertices[1]))<0.000001&&abs(vertices[0].len(vertices[1])-vertices[3].len(vertices[2]))<0.000001&&abs(vertices[0].len(vertices[1])-vertices[3].len(vertices[0]))<0.00001)
			return true;
		}
		else
			return false;
	}
	double Trapezium::getArea()
	{
		if (isValid())
		{
			if (abs(vertices[0].vectorproportion(vertices[1]) - vertices[3].vectorproportion(vertices[2])) < 0.00001)
			{
				double cos;
				cos = vertices[1].dotproduct(vertices[0], vertices[2]) /(vertices[0].len(vertices[1])*vertices[1].len(vertices[2]));
				double sin;
				sin = sqrt(1 - cos*cos);
				return ((vertices[0].len(vertices[1]) + vertices[2].len(vertices[3]))*vertices[1].len(vertices[2])*sin)/2;
			}
			else if ((abs(vertices[1].vectorproportion(vertices[2]) - vertices[0].vectorproportion(vertices[3])) < 0.00001))
			{
				double cos;
				cos = vertices[2].dotproduct(vertices[1], vertices[3]) / (vertices[1].len(vertices[2])*vertices[2].len(vertices[3]));
				double sin;
				sin = sqrt(1 - cos*cos);
				return ((vertices[0].len(vertices[3]) + vertices[1].len(vertices[2]))*vertices[2].len(vertices[3])*sin)/ 2;
			}
		}
		else
			return -1;
	}
	bool Trapezium::isValid()
	{
		if (abs(vertices[0].vectorproportion(vertices[1]) - vertices[3].vectorproportion(vertices[2])) < 0.001)
		{
			if (abs(vertices[1].vectorproportion(vertices[2]) - vertices[0].vectorproportion(vertices[3])) < 0.001)
				return true;
		}
		else if (abs(vertices[1].vectorproportion(vertices[2]) - vertices[0].vectorproportion(vertices[3]))< 0.0001)
		{
			if (abs(vertices[0].vectorproportion(vertices[1]) - vertices[3].vectorproportion(vertices[2])) < 0.001)
				return true;
		}
		else
			return false;
	}
	double Pentagon::getArea()
	{
		if (isValid())
			return ((vertices[1] - vertices[0])*(vertices[2] - vertices[0])) + ((vertices[2] - vertices[0])*(vertices[3] - vertices[0])) + ((vertices[3] - vertices[0])*(vertices[4] - vertices[0]));
		else
			return -1;
	}
	bool Pentagon::isValid()
	{
		if (vertices.size() == 5)
		{
			double arr[100];
			std::vector<Vertex>convex(vertices);
			convex.push_back(vertices[0]);
			convex.push_back(vertices[1]);
			for (int i = 0; i < convex.size() - 2; i++)
			{
				arr[i] = (convex[i] - convex[i + 1]).verconvex(convex[i + 1] - convex[i + 2]);
			}
			for (int i = 0; i < convex.size(); i++)
			{
				if (abs(arr[i]) < 0.0000000001)
					return false;
			}
			return true;
		}
		else
			return false;
	}
	double Polygon::getArea()
	{
		double sum=0;
		if (isValid())
		{
			for (int i = 1; i < vertices.size() - 1; i++)
			{
				sum += (vertices[i] - vertices[0])*(vertices[i + 1] - vertices[0]);
			}
			return sum;
		}
		else
			return -1;
	}
	bool Polygon::isValid()
	{
		if (vertices.size() >= 3)
		{
			double arr[100];
			std::vector<Vertex>convex(vertices);
			convex.push_back(vertices[0]);
			convex.push_back(vertices[1]);
			for (int i = 0; i < convex.size() - 2; i++)
			{
				arr[i] = (convex[i] - convex[i + 1]).verconvex(convex[i + 1] - convex[i + 2]);
			}
			for (int i = 0; i < convex.size(); i++)
			{
				if (abs(arr[i]) < 0.0000000001)
					return false;
			}
			return true;
		}
		else
			return false;
	}
}