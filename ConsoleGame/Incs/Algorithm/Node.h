#pragma once

#include <iostream>
#include <Math/Vector2.h>

// ��� Ŭ����.
class Node
{
public:
    Node(Vector2 vector, Node* parent = nullptr)
        : position(vector), parent(parent)
    {
    }

    ~Node() = default;

    // ������ �����ε�.
    Vector2 operator-(const Node& other)
    {
        return Vector2(position.x - other.position.x, position.y - other.position.y);
    }

    bool operator==(const Node& other) const
    {
        return position.x == other.position.x && position.y == other.position.y;
    }

public:
    // ����� ��ġ.
    Vector2 position;

    // ���.
    // ���� ��忡�� �̵� �������� ���.
    float gCost = 0.0f;
    // �̵� ��忡�� ��ǥ �������� ���(�޸���ƽ, ����)
    float hCost = 0.0f;
    // �� ����� ��ģ ���.
    float fCost = 0.0f;

    // ��ũ �ʵ�(�θ� ���).
    Node* parent = nullptr;
};