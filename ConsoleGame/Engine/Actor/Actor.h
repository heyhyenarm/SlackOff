#pragma once

#include "Core.h"
#include "RTTI.h"
#include "Math/Vector2.h"
#include "ImageComponent.h"
#include "TransformComponent.h"

// ������ �⺻ ��ü.
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
	// ������ ��ġ.
	Vector2 position;

	// Ȱ��ȭ ���������� ��Ÿ���� ����.
	bool isActive;

	// ������ ���� ��û�� �ƴ��� ���θ� ��Ÿ���� ����.
	bool isExpired;
};