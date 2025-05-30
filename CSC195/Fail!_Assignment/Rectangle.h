#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(float w, float h) : m_width(w), m_height(h) {} // Takes both inputs
	~Rectangle() override {}

	float Area() const override // override the pure virtual method to use
	{
		return m_width * m_height;
	}

private:
	float m_width;
	float m_height;
};