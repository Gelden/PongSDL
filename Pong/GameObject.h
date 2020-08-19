#pragma once  
#include "Texture.h"
#include "Vector2.h"
class GameObject
{
protected: 
	Texture* mTexture; 
	Vector2 mTranform; 
public: 
	GameObject() :mTexture(NULL), mTranform(Vector2(0,0)) {} 
	~GameObject() {}  

	float Width() const { return (float)mTexture->GetWidth(); }
	float Height() const { return (float)mTexture->GetHeight(); } 

	float Left() const { return mTranform.X - 0.5f * Width(); }
	float Right() const { return mTranform.X + 0.5 * Width(); }
	float Top() const { return mTranform.Y - 0.5f * Height(); }
	float Bottom() const { return mTranform.Y + 0.5f * Height(); }
};