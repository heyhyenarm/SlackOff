#pragma once

#include <iostream>
#include <Math/Vector2.h>

// 노드 클래스.
class Node
{
public:
    Node(Vector2 vector, Node* parent = nullptr)
        : position(vector), parent(parent)
    {
    }

    ~Node() = default;

    // 연산자 오버로딩.
    Vector2 operator-(const Node& other)
    {
        return Vector2(position.x - other.position.x, position.y - other.position.y);
    }

    bool operator==(const Node& other) const
    {
        return position.x == other.position.x && position.y == other.position.y;
    }

public:
    // 노드의 위치.
    Vector2 position;

    // 비용.
    // 현재 노드에서 이동 노드까지의 비용.
    float gCost = 0.0f;
    // 이동 노드에서 목표 노드까지의 비용(휴리스틱, 추정)
    float hCost = 0.0f;
    // 두 비용을 합친 비용.
    float fCost = 0.0f;

    // 링크 필드(부모 노드).
    Node* parent = nullptr;
};