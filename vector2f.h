#ifndef VECTOR2F_H_
#define VECTOR2F_H_

#include "consts.hpp"

/*
 * A 2D float vector with an x and y component
 */
class Vector2f {
public:
	Vector2f(float ax = 0, float ay = 0);

	static float getDirection(const float& x1, const float& y1, const float& x2, const float& y2);

	Vector2f operator+(const Vector2f& other);
	Vector2f operator+=(const Vector2f& other);
	Vector2f operator-(const Vector2f& other);
	Vector2f operator-=(const Vector2f& other);
	Vector2f operator*(const float& other);
	Vector2f operator*=(const float& other);
	Vector2f operator/(const float& other);
	Vector2f operator/=(const float& other);
	
	Vector2f normalised();

	void reset();
	void normalise();
	void rotate(const float& angle);
	void angle_to(float dir = 0, float mag = 0);

	float getMagnitude() const;

	float x;
	float y;
};

#endif
