#pragma once

#include "Core.h"
#include "RTTI.h"
#include <Vector>

class Actor;
class ENGINE_API Level : public RTTI
{
	RTTI_DECLARATIONS(Level, RTTI)

public:
	explicit Level();
	virtual ~Level();

	void AddActor(Actor* newActor);

	// ���� ��û�� �� ���͸� �����ϴ� �Լ�.
	void ProcessAddedAndDestroyedActor();

	//������ ������Ʈ. 
	virtual void Update(float deltaTime);
	//�ܼ� ȭ�鿡 �׸���. 
	virtual void Draw();
	//Todo: ���� �غ� �Ϸ� �ݹ�. 

protected:

	std::vector <Actor*> actors;

	// �߰� ��û�� ����.
	Actor* addRequestedActor = nullptr;
};