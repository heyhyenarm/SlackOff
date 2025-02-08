#pragma once
#include <string>
#include <Core.h>

class ImageComponent
{
public:
	explicit ImageComponent(const std::wstring image = L"");

	void SetImage(const std::wstring image);
	void SetImage(const std::wstring directory, FILE file);

	inline void SetActorColor(Color color) { color = color; };

private:
	std::wstring image;
	Color color;
};