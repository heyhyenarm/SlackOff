#pragma once

#include <vector>

#include "Core.h"

// A* ��ã�� ��� ó�� Ŭ����.
class Node;
class Maze
{
    // �̵� ���� ����ü.
    struct Direction
    {
        // ����.
        int x = 0;
        int y = 0;

        // ���.
        float cost = 0.0f;
    };

public:
    Maze();
    ~Maze();

    // �̷� ���� �Լ�. 
    void GenerateMaze(int width, int height);

    // �׸��� ��� �Լ�.
    void DisplayGrid(const std::vector<std::vector<int>>& grid);

private:
    void RecursiveGenerateMaze(std::vector<std::vector<int>>& grid, int width, int height);

private:
    // �̷�. 
    std::vector<std::vector<int>> maze;

    // ���� ����Ʈ.
    std::vector<Node*> openList;

    // ���� ����Ʈ.
    std::vector<Node*> closedList;

    // ���� ���.
    Node* startNode = nullptr;

    // ��ǥ ���.
    Node* goalNode = nullptr;

    std::vector<Direction> directions;
};