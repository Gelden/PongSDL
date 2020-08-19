#include <math.h>
#include "Vector2.h"

Vector2 Vector2::operator*(const float& rhs)
{
	return Vector2(this->X * rhs, this->Y * rhs);
}

Vector2 Vector2::operator/(const float& rhs)
{
	return Vector2(this->X / rhs, this->Y / rhs);
}

Vector2 Vector2::operator*(const int& rhs)
{
	return Vector2(this->X * rhs, this->Y * rhs);
}

Vector2 Vector2::operator/(const int& rhs)
{
	return Vector2(this->X / rhs, this->Y / rhs);
}

Vector2 Vector2::operator+(const float& rhs)
{
	return Vector2(this->X + rhs, this->Y + rhs);
}

Vector2 Vector2::operator-(const float& rhs)
{
	return Vector2(this->X - rhs, this->Y - rhs);
}

Vector2 Vector2::operator+(const int& rhs)
{
	return Vector2(this->X + rhs, this->Y + rhs);
}

Vector2 Vector2::operator-(const int& rhs)
{
	return Vector2(this->X - rhs, this->Y - rhs);
}

Vector2& Vector2::operator+=(const float& rhs)
{
	this->X += rhs;
	this->Y += rhs;
	return *this;
}

Vector2& Vector2::operator-=(const float& rhs)
{
	this->X -= rhs;
	this->Y -= rhs;
	return *this;
}

Vector2& Vector2::operator+=(const int& rhs)
{
	this->X += rhs;
	this->Y += rhs;
	return *this;
}

Vector2& Vector2::operator-=(const int& rhs)
{
	this->X -= rhs;
	this->Y -= rhs;
	return *this;
}

Vector2& Vector2::operator*=(const float& rhs)
{
	this->X *= rhs;
	this->Y *= rhs;
	return *this;
}

Vector2& Vector2::operator/=(const float& rhs)
{
	this->X /= rhs;
	this->Y /= rhs;
	return *this;
}

Vector2& Vector2::operator*=(const int& rhs)
{
	this->X *= rhs;
	this->Y *= rhs;
	return *this;
}

Vector2& Vector2::operator/=(const int& rhs)
{
	this->X /= rhs;
	this->Y /= rhs;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
	return Vector2(this->X + rhs.X, this->Y + rhs.Y);
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	return Vector2(this->X - rhs.X, this->Y - rhs.Y);
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	this->X += rhs.X;
	this->Y += rhs.Y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	this->X -= rhs.X;
	this->Y -= rhs.Y;
	return *this;
}

float Vector2::Magnitude()
{
	return sqrt(X * X + Y * Y);
}

Vector2 Vector2::Normalize()
{
	return Vector2();
	float r = 1 / Magnitude();
	return Vector2(X * r, Y * r);
}
