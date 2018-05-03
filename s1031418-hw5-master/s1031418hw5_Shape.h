#pragma once
#include "s1031418hw5_main.h"

namespace MIME{
	class Vertex{//�I
	public:
		Vertex() : x(0.0f), y(0.0f){}
		Vertex(const float inX, const float inY) : x(inX), y(inY){}
		void print(){ std::cout << "(" << x << "," << y << ")"; }
		Vertex  operator-(const Vertex &right);
		double  operator*(const Vertex &right);
		bool operator== (const Vertex &right);
		double dotproduct(const Vertex &point1, const Vertex &point2);
		double len(const Vertex &right);
		double verconvex(const Vertex &point1);
		double vectorproportion(const Vertex &right);
		float x, y;
		friend std::ostream &operator<<(std::ostream &output, const Vertex &in);
		
	};

	class Shape{//�Ϊ�
	public:
		Shape() : CurrentType(ShapeType::Shape){}
		//add a Vertex
		size_t addVertex(const Vertex inV){ vertices.push_back(inV); return vertices.size(); }
		size_t addVertex(const float inX, const float inY){ vertices.push_back(Vertex(inX, inY)); return vertices.size(); }
		void print();
		ShapeType getType();
		virtual double getArea()=0;
		virtual bool isValid()=0;
	    bool isConvex();
	protected:
		ShapeType CurrentType;
		std::vector<Vertex> vertices;
	};
	class Triangle : public Shape//�T����
	{
	public:
		Triangle(){
			CurrentType = ShapeType::Triangle;
		}
		double getArea();
		bool isValid();
	};
	class Isosceles_Triangle :public Triangle//���y�T����
	{
	public:
		Isosceles_Triangle(){
			CurrentType = ShapeType::Isosceles_triangle;
		}
		bool isValid();
		double getArea();
	};
	class Regular_Triangle :public Isosceles_Triangle //���T����
	{
	public:
		Regular_Triangle(){
			CurrentType = ShapeType::Regular_triangle;
		}
		bool isValid();
		double getArea();
	};
	class Right_triangle :public Triangle //�����T����
	{
	public:
		Right_triangle(){
			CurrentType = ShapeType::Right_triangle;
		}
		bool isValid();
		double getArea();
		
	};
	class Quadrilateral :public Shape//�|���
	{
	public:
		Quadrilateral(){
			CurrentType = ShapeType::Quadrilateral;
		}
		double getArea();
		bool isValid();
	};
	class Parallelogrm :public Quadrilateral//����|���
	{ 
	public:
		Parallelogrm()
		{
			CurrentType = ShapeType::Parallelogram;
		}
		bool isValid();
		double getArea();
	};
	class Square :public Parallelogrm//����
	{ 
	public:
		Square(){
			CurrentType = ShapeType::Square;
		}
		bool isValid();
		double getArea();
	};
	class Trapezium :public Quadrilateral//���
	{ 
	public:
		Trapezium()
		{
			CurrentType = ShapeType::Trapezium;
		}
	bool isValid();
	double getArea();
	};
	class Pentagon : public Shape//�����
	{ 
	public:
		Pentagon(){
			CurrentType = ShapeType::Pentagon;
		}
		double getArea();
		bool isValid();
	};

	class Polygon :public Shape//�h���
	{ 
	public:
		Polygon(){
			CurrentType = ShapeType::Polygon;
		}
		double getArea();
		bool isValid();
	};
}