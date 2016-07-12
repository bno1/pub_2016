#pragma once

#include <inttypes.h>

template<typename T>
class Color {
public:
	T r, g, b;

	Color() : r(0), g(0), b(0) {}
	Color(T gray) : r(gray), g(gray), b(gray) {}
	Color(T r, T g, T b) : r(r), g(g), b(b) {}
	Color(const Color &c) : r(c.r), g(c.g), b(c.b) {}

	// TODO operators
};