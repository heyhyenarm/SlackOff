#pragma once

#include "Core.h"

class ENGINE_API Vector2
{
public:
	Vector2(int x = 0, int y = 0);
	~Vector2() = default;

	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator+=(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

	static const Vector2 Zero;
	static const Vector2 One;
	static const Vector2 Up;
	static const Vector2 Down;
	static const Vector2 Right;
	static const Vector2 Left;

public:
	int x = 0;
	int y = 0;
};