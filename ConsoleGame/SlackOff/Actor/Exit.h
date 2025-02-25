#pragma once

#include "Actor/Actor.h"

class Exit : public Actor
{
	RTTI_DECLARATIONS(Exit, Actor)

public:
	Exit();
	~Exit() = default;

	virtual void Update(float delatTime)override;
	virtual void Draw() override;

	inline virtual void SetPosition(const Vector2& newPosition) override { position = newPosition; };


private:

};