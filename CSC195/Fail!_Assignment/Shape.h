#pragma once
class Shape 
{
public:
	virtual ~Shape() {} // Virtual Deconstructor
	virtual float Area() const = 0; // Pure virtual method needs to be defined
};

