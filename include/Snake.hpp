#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Board.hpp"


enum class Direction { Right,Left,Upward,Downward };

constexpr int max_length = 25;

class Snake{
public:

    Snake();

    virtual ~Snake()noexcept { delete brd; }

public:
    void Move();

    void SetKeyBoard();

private:
    Direction m_dir;
    Board *brd;

private:
    bool overGame;
};

#endif // SNAKE_HPP
