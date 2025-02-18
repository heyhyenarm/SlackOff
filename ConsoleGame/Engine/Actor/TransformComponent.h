#pragma once
#include "Math/Vector2.h"

class TransformComponent
{
public:
	virtual void SetTransform(Vector2 vector) = 0;
	virtual Vector2 GetTransform() = 0;

protected:
	int x = 0;
	int y = 0;
};