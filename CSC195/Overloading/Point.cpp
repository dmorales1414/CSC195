#include "Point.h"

void ost::Point::Write(ostream& ostream)
{
	ostream << x << " : " << y << endl;
}

void ost::Point::Add(Point& point)
{
	x += point.x;    // x = x + point.x;
	y += point.y;    // y = y + point.y;
}

ost::Point ost::Point::operator+(Point& p2)
{
	Point sumPoint;

	sumPoint.x = x + p2.x;

	x += p2.x;
	y += p2.y;

	return sumPoint;
}

ost::Point ost::Point::operator-(Point point)
{
	// ost::Point point3;
	//point3.x = point1.x - point2.x;
	//point3.y = point1.y - point2.y;
	//return point3;

	return Point(x - point.x, y - point.y);
}

ost::Point ost::Point::operator*(float point)
{
	return Point(x * point, y * point);
}

ostream& ost::operator<<(ostream& ostream, ost::Point& point)
{
	// TODO: insert return statement here
	ostream << point.x << " : " << point.y << endl;
	return ostream;
}
