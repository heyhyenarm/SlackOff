#include "PreCompiledHeader.h"
#include "Vector2.h"

Vector2::Vector2(int x, int y)
    : x(x), y(y)
{
}

Vector2 Vector2::operator+(const Vector2& other)
{
    Vector2 newVector;
    newVector.x = this->x + other.x;
    newVector.y = this->y + other.y;
    return newVector;
}

Vector2 Vector2::operator-(const Vector2& other)
{
    Vector2 newVector;
    newVector.x = this->x - other.x;
    newVector.y = this->y - other.y;
    return newVector;
}

bool Vector2::operator==(const Vector2& other)
{
    return this->x == other.x && this->y && other.y;
}

bool Vector2::operator!=(const Vector2& other)
{
    return this->x != other.x || this->y != other.y;
}
