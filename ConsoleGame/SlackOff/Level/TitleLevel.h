#pragma once

#include "Level/Level.h"
#include <string>

class TitleLevel : public Level
{
	RTTI_DECLARATIONS(TitleLevel, Level)
public:
	explicit TitleLevel(std::wstring directory, FILE* file);
	~TitleLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

private:
	std::wstring image;
};