#pragma once

#include "Actor/Actor.h"

class Ground : public Actor
{
	RTTI_DECLARATIONS(Ground, Actor)

public:

	Ground();
	~Ground() = default;

	virtual void Update(float delatTime)override;
	virtual void Draw() override;

	inline virtual void SetPosition(const Vector2& newPosition) override { position = newPosition; };

private:

};