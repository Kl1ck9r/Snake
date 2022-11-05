#include "Snake.hpp"
<<<<<<< HEAD
=======
#include <iostream>
#include <stdexcept>
>>>>>>> f2fb1b8 (formatting)

int main() 
{
  try {
    Snake snake;
    snake.Start();
  } catch (std::exception &_error) {
    std::cerr << _error.what();
  }

  return 0;
}
