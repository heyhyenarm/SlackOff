#include "TitleLevel.h"

TitleLevel::TitleLevel(const std::wstring directory, FILE* file)
	: Level()
{
	image = LoadFile(directory, file);
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);
}

void TitleLevel::Draw()
{
	Super::Draw();
}
