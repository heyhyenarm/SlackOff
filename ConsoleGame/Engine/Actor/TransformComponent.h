#pragma once
#include "Math/Vector2.h"

class TransformComponent
{
public:
	virtual void SetTransform() = 0;
	virtual Vector2 GetTransform() = 0;

protected:
	int x = 0;
	int y = 0;
};