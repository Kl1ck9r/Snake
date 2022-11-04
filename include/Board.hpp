#ifndef BOARD_HPP
#define BOARD_HPP

constexpr int Width = 30;
constexpr int Height = 20;


class Board{
public:
    Board();

    virtual ~Board() noexcept {  }

public:
    void DrawBoard();

    void UseSettings();

    void Counter();

    void GetX_YSnake();

public:
    int xP = { 0 } ;
    int yP = { 0 };

    int tailX[40],tailY[40];

    int nTail= { 0 };

    bool OverGame = false ;

private:
    int xP_food = { 0 };
    int yP_food = { 0 };

    int score= { 0 };

};
#endif // BOARD_HPP
