#include "Snake.hpp"

std::vector<body_snake> m_snake;

void Snake::SnakeInit() {
  for (int i = 0; i < 5; i++) {
    body_snake m_body;
    m_body.x = -10;
    m_body.y = -10;

    m_snake.push_back(m_body);
  }

  m_snake[0].x = 5;
  m_snake[0].y = 3;
}

void Snake::ViewField() {
  system("clear");

  for (int i = 0; i <= HEIGHT; i++) {
    for (int j = 0; j <= WIDTH; j++) {

      if (isBoard(j, i)) {
        std::cout << '#';
      }

      else if (isBody(j, i)) {
        std::cout << '*';
      }

      else if (isFood(j, i)) {
        std::cout << type_food[num_food];
      }

      else
        std::cout << ' ';
    }
    std::cout << '\n';
  }

  std::cout << "SCORE: " << m_score << std::endl;
}

void Snake::GenerateFood() {
  srand(time(nullptr));

  xFruit = rand() % (WIDTH - 3);
  yFruit = rand() % (HEIGHT - 3);

  num_food = rand() % sizeof(type_food);
}

void Snake::MoveSnake() {
  int l_x = m_snake[0].x;
  int l_y = m_snake[0].y;

  switch (m_dir) {
  case Direction::LEFT:
    m_snake[0].x--;
    break;
  case Direction::RIGHT:
    m_snake[0].x++;
    break;
  case Direction::DOWN:
    m_snake[0].y++;
    break;
  case Direction::UP:
    m_snake[0].y--;
    break;
  default:
    break;
  }

  for (int i = 0; i < m_snake.size(); i++) {
  }
}

void Snake::Start() {
  fd_set rfds;
  timeval timeout;

  timeout.tv_sec = 0;
  timeout.tv_usec = 0;

  GenerateFood();
  SnakeInit();

  while (true) {
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);

    if (select(1, &rfds, NULL, NULL, &timeout) > 0 &&
        FD_ISSET(STDIN_FILENO, &rfds)) {
      switch (getchar()) {
      case 100:
      case 68:
        if (m_dir != Direction::LEFT)
          m_dir = Direction::RIGHT;
        break;

      case 83:
      case 115:
        if (m_dir != Direction::UP)
          m_dir = Direction::DOWN;
        break;

      case 65:
      case 97:
        if (m_dir != Direction::RIGHT)
          m_dir = Direction::LEFT;

        break;

      case 119:
      case 87:
        if (m_dir != Direction::DOWN)
          m_dir = Direction::UP;
        break;
      default:
        break;
      }
    }
    MoveSnake();

    if (AteFood()) {
      GenerateFood();

      body_snake snake_peace;
      snake_peace.y = m_snake[m_snake.size() - 1].y;
      snake_peace.x = m_snake[m_snake.size() - 1].x;

      m_snake.push_back(snake_peace);

      m_score += 7;
    }

    if (OfBoard()) {
      exit(1);
    }

    ViewField();
    usleep(100000);
  }
}

bool Snake::OfBoard() {
  return m_snake[0].x == 0 || m_snake[0].x == WIDTH || m_snake[0].y == 0 ||
         m_snake[0].y == HEIGHT;
}

bool Snake::isBoard(int x, int y) {
  return x == WIDTH || y == HEIGHT || y == 0 || x == 0;
}

bool Snake::isFood(int x, int y) { return xFruit == x && yFruit == y; }

bool Snake::isBody(int x, int y) {
  for (int i = 0; i < m_snake.size(); i++) {
    if (m_snake[i].y == y && m_snake[i].x == x) {
      return true;
    }
  }

  return false;
}

bool Snake::AteFood() {
  for (int i = 0; i < m_snake.size(); i++) {
    if (m_snake[i].x == xFruit && m_snake[i].y == yFruit) {
      return true;
    }
  }

  return false;
}
