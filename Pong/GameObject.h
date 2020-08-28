#pragma once  
#include "Texture.h"
#include "Vector2.h"
class GameObject
{
protected: 
	Texture* mTexture; 
	Vector2 mPosition; 
public: 
	GameObject() :mTexture(NULL), mPosition(Vector2(0,0)) {} 
	~GameObject() {}  

	float Width() const { return (float)mTexture->GetWidth(); }
	float Height() const { return (float)mTexture->GetHeight(); } 

	//Collision Accessors
	float Left() { return mPosition.X - 0.5f * Width(); }
	float Right() const { return mPosition.X + 0.5 * Width(); }
	float Top() const { return mPosition.Y - 0.5f * Height(); }
	float Bottom() const { return mPosition.Y + 0.5f * Height(); } 
	//Position Mutators
	void SetLeft(float x) { mPosition.X = x + 0.5f * Width(); }
	void SetRight(float x) { mPosition.X = x - 0.5f * Width(); }
	void SetTop(float y) { mPosition.Y = y + 0.5 * Height(); }
	void SetBottom(float y) { mPosition.Y = y - 0.5 * Height(); } 
};