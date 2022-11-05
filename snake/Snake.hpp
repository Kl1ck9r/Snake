#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <vector>

enum class Direction { UP, DOWN, LEFT, RIGHT };

struct body_snake {
  int x;
  int y;
};

class Snake {
public:
  Snake() = default;
  ~Snake() = default;

public:
  void SnakeInit();

  void ViewField();

  void GenerateFood();

  void MoveSnake();

  void Start();

public:
  bool OfBoard();

  bool isBoard(int x, int y);

  bool isFood(int x, int y);

  bool isBody(int x, int y);

  bool AteFood();

private:
  int xFruit = {0};
  int yFruit = {0};
  int m_score = {0};

private:
  static constexpr int WIDTH = 40;
  static constexpr int HEIGHT = 10;

private:
  Direction m_dir = Direction::RIGHT;
  std::size_t num_food;
  std::vector<body_snake> m_snake;

  const char type_food[3] = {'#', '%', '$'};
};

#endif // SNAKE_HPP
