#pragma once 
/*******************************************************************************************
 * Vector2 object represents two co-odinates (floating point values) within 2D game space. *
 * Written by: Gelden                                                                      *
 * August 2020                                                                             *
 *******************************************************************************************/

#pragma once 
class Vector2
{
public:
	//FIELDS
	float X;
	float Y;
	//CONSTRUCTORS 
	Vector2() : X(0.0), Y(0.0) {} //Default constuctor sets x & y to 0.0 
	~Vector2() {} //Destructor
	Vector2(float pX, float pY) : X(pX), Y(pY) {} //Constuction with X & Y parameters  
	Vector2(const Vector2& v) : X(v.X), Y(v.Y) {} //Copy constuctor   

	//SCALAR OPERATORS  
	Vector2 operator* (const float& rhs);
	Vector2 operator/ (const float& rhs);
	Vector2 operator* (const int& rhs);
	Vector2 operator/ (const int& rhs);

	Vector2 operator+(const float& rhs);
	Vector2 operator-(const float& rhs);
	Vector2 operator+(const int& rhs);
	Vector2 operator-(const int& rhs);

	Vector2& operator+=(const float& rhs);
	Vector2& operator-=(const float& rhs);
	Vector2& operator+=(const int& rhs);
	Vector2& operator-=(const int& rhs);

	Vector2& operator*=(const float& rhs);
	Vector2& operator/=(const float& rhs);
	Vector2& operator*=(const int& rhs);
	Vector2& operator/=(const int& rhs);

	//ARITHMATIC OPERATORS
	Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);
	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);

	//UTILITY FUNCTIONS 
	float Magnitude();
	Vector2 Normalize();

};

