#pragma once

#include "Level/Level.h"
#include <string>

class TitleLevel : public Level
{
	RTTI_DECLARATIONS(TitleLevel, Level)

public:
	explicit TitleLevel(std::wstring titleImage);
	~TitleLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

	void LoadImageFile(std::wstring directory);

private:
	std::wstring image;
};