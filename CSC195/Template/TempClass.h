#include <iostream>
using namespace std;

#pragma once

template<typename T = int>
class TempClass
{
private:
	T x, y;
public:
	TempClass() : x{ 0 }, y{ 0 } {}
	TempClass(T x, T y) : x{x}, y{y} {}
};


template <typename T, int size>
class TempArray
{
private:
	T m_elements[size];

public:
	T operator [] (int index) {return m_elements.length}
};