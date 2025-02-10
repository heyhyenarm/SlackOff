#pragma once
#include <string>
#include <Core.h>

class ImageComponent
{
public:
	virtual void SetImage(const std::string image = "") = 0;
	virtual void SetColor(Color color) = 0;
	virtual std::string GetImage() = 0;

protected:
	std::string image;
	Color color;
};

//class ImageComponent
//{
//public:
//	explicit ImageComponent(const std::wstring image = L"");
//
//	virtual void SetImage(const std::wstring image);
//	virtual void SetImage(const wchar_t* directory, FILE* file);
//
//	inline virtual void SetActorColor(Color color) { color = color; };
//
//private:
//	std::wstring image;
//	Color color;
//};