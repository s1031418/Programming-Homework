#pragma once
#include "s1031418hw5_main.h"

namespace MIME{
	class Vertex{//點
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

	class Shape{//形狀
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
	class Triangle : public Shape//三角形
	{
	public:
		Triangle(){
			CurrentType = ShapeType::Triangle;
		}
		double getArea();
		bool isValid();
	};
	class Isosceles_Triangle :public Triangle//等腰三角形
	{
	public:
		Isosceles_Triangle(){
			CurrentType = ShapeType::Isosceles_triangle;
		}
		bool isValid();
		double getArea();
	};
	class Regular_Triangle :public Isosceles_Triangle //正三角形
	{
	public:
		Regular_Triangle(){
			CurrentType = ShapeType::Regular_triangle;
		}
		bool isValid();
		double getArea();
	};
	class Right_triangle :public Triangle //直角三角形
	{
	public:
		Right_triangle(){
			CurrentType = ShapeType::Right_triangle;
		}
		bool isValid();
		double getArea();
		
	};
	class Quadrilateral :public Shape//四邊形
	{
	public:
		Quadrilateral(){
			CurrentType = ShapeType::Quadrilateral;
		}
		double getArea();
		bool isValid();
	};
	class Parallelogrm :public Quadrilateral//平行四邊形
	{ 
	public:
		Parallelogrm()
		{
			CurrentType = ShapeType::Parallelogram;
		}
		bool isValid();
		double getArea();
	};
	class Square :public Parallelogrm//正方
	{ 
	public:
		Square(){
			CurrentType = ShapeType::Square;
		}
		bool isValid();
		double getArea();
	};
	class Trapezium :public Quadrilateral//梯形
	{ 
	public:
		Trapezium()
		{
			CurrentType = ShapeType::Trapezium;
		}
	bool isValid();
	double getArea();
	};
	class Pentagon : public Shape//五邊形
	{ 
	public:
		Pentagon(){
			CurrentType = ShapeType::Pentagon;
		}
		double getArea();
		bool isValid();
	};

	class Polygon :public Shape//多邊形
	{ 
	public:
		Polygon(){
			CurrentType = ShapeType::Polygon;
		}
		double getArea();
		bool isValid();
	};
}