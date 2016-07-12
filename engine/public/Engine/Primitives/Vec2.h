#pragma once

namespace Engine
{

template<typename T>
class Vec2 {
public:
	T x, y;

	Vec2() : x(0), y(0) {}
	Vec2(T x, T y) : x(x), y(y) {}
	Vec2(const Vec2 &v) : x(v.x), y(v.y) {}

	// TODO operators

	Vec2& operator+=(const Vec2<T> &v) {
		x += v.x;
		y += v.y;
		return *this;
	}
};

}