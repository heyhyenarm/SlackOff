#pragma once

#include "Core.h"
#include "RTTI.h"
#include "Math/Vector2.h"
#include "ImageComponent.h"
#include "TransformComponent.h"

// 레벨의 기본 물체.
class ENGINE_API Actor : public RTTI, public ImageComponent, public TransformComponent
{
	RTTI_DECLARATIONS(Actor, RTTI)

		friend class Level;

public:
	Actor();
	virtual ~Actor();

	virtual void Update(float delatTime);
	virtual void Draw();

	inline virtual void SetPosition(const Vector2& newPosition) { position = newPosition; };
	inline Vector2 GetPosition() const { return position; };

	inline bool IsAcive() const { return isActive && !isExpired; }
	inline void SetActive(bool active) { isActive = active; }
	inline void Destroy() { isExpired = true; }

protected:
	// 액터의 위치.
	Vector2 position;

	// 활성화 상태인지를 나타내는 변수.
	bool isActive;

	// 액터의 제거 요청이 됐는지 여부를 나타내는 변수.
	bool isExpired;
};