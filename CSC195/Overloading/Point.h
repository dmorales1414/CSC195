#pragma once
#include <iostream>
using namespace std;

namespace ost
{
	class Point
	{
	private:
		float x, y;

	public:
		//Point() { x = 0, y = 0; } // 2-step process
		Point() : x{ 0 }, y{ 0 } {} // Single step process
		Point(float x, float y) : x{ x }, y{ y } {}

		void Write(ostream& ostream);

		void Add(Point& point);
		Point operator + (Point& p2);
		Point operator - (Point point);
		Point operator * (float point);

		// friend - access private variables in a non-member function
		friend ostream& operator << (ostream& ostream, ost::Point& point);
	};
}
