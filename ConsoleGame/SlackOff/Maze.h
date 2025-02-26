#pragma once

#include <vector>

#include "Core.h"

// A* 길찾기 기능 처리 클래스.
class Node;
class Maze
{
    // 이동 방향 구조체.
    struct Direction
    {
        // 방향.
        int x = 0;
        int y = 0;

        // 비용.
        float cost = 0.0f;
    };

public:
    Maze();
    ~Maze();

    // 미로 생성 함수. 
    void GenerateMaze(int width, int height);

    // 그리드 출력 함수.
    void DisplayGrid(const std::vector<std::vector<int>>& grid);

private:
    void RecursiveGenerateMaze(std::vector<std::vector<int>>& grid, int width, int height);

private:
    // 미로. 
    std::vector<std::vector<int>> maze;

    // 열린 리스트.
    std::vector<Node*> openList;

    // 닫힌 리스트.
    std::vector<Node*> closedList;

    // 시작 노드.
    Node* startNode = nullptr;

    // 목표 노드.
    Node* goalNode = nullptr;

    std::vector<Direction> directions;
};