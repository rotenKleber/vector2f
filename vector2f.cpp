#include "vector2f.h"

Vector2f::Vector2f(float ax, float ay) {
	x = ax;
	y = ay;
}

// returns the direction of the vectore
float Vector2f::getDirection(const float& x1, const float& y1, const float& x2, const float& y2) {
	if(x2 > x1) {
		if(y2 < y1) {
			return atan((y2-y1)/(x2-x1)) + 2*PI;
		} else if(y2 > y1) {
			return atan((y2-y1)/(x2-x1));
		} else {
			return 0;
		}
	} else if(x2 < x1) {
			return atan((y2-y1)/(x2-x1)) + PI;
	} else {
		if(y2 < y1) {
			return 3.f*PI/2.f;
		} else {
			return PI/2.f;
		}
	}
}

// Overloading + operator to work with vectors
Vector2f Vector2f::operator+(const Vector2f& other) {
	Vector2f added(x + other.x, y + other.y);
	return added;
}

// Overloading += operator to work with vectors
Vector2f Vector2f::operator+=(const Vector2f& other) {
	x += other.x;
	y += other.y;
	return *this;
}

// Overloading - operator to work with vectors
Vector2f Vector2f::operator-(const Vector2f& other) {
	Vector2f added(x - other.x, y - other.y);
	return added;
}

// Overloading -= operator to work with vectors
Vector2f Vector2f::operator-=(const Vector2f& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

// Overloading * operator to work with vectors (scalar)
Vector2f Vector2f::operator*(const float& other) {
	Vector2f scaled(x * other, y * other);
	return scaled;
}

// Overloading *= operator to work with vectors (scalar)
Vector2f Vector2f::operator*=(const float& other) {
	x *= other;
	y *= other;
	return *this;
}

// Overloading / operator to work with vectors (scalar)
Vector2f Vector2f::operator/(const float& other) {
	Vector2f scaled(x / other, y / other);
	return scaled;
}

// Overloading /= operator to work with vectors (scalar)
Vector2f Vector2f::operator/=(const float& other) {
	x /= other;
	y /= other;
	return *this;
}

// Normalised version of the vector
Vector2f Vector2f::normalised() {
	Vector2f scaled = *this;
	float magnitude = sqrt(pow(x, 2) + pow(y, 2));
	
	scaled.x /= magnitude;
	scaled.y /= magnitude;
	
	return scaled;
}

// Resets the vector to <0.0f, 0.0f>
void Vector2f::reset() {
	x = 0;
	y = 0;
}

// Normalises the vector
void Vector2f::normalise() {
	float magnitude = sqrt(pow(x, 2) + pow(y, 2));
	x /= magnitude;
	y /= magnitude;
}

// Rotates the vector (using radians)
void Vector2f::rotate(const float& angle) {
	// Uses rotation matrix for arithmetic
	float x2, y2;
	x2 = x*cos(angle) - y*sin(angle);
	y2 = x*sin(angle) + y*cos(angle);
	x = x2;
	y = y2;
}

// Sets the directoin of the vector to the angle provided, as well as the magnitude
void Vector2f::angle_to(float dir, float mag) {
	x = mag*cos(dir);
	y = mag*sin(dir);
}


// Returns the magnitude of the vector
float Vector2f::getMagnitude() const{
	return sqrt(pow(x, 2) + pow(y, 2));
}
