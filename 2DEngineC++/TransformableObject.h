#pragma once
class TransformableObject
{
public:

	virtual void translate(int x, int y) = 0;
    virtual void rotate(float angle) = 0;
	virtual void scale(float x, float y) = 0;
};

