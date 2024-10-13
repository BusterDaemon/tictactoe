#include "./src/tictactoe.hxx"
#include <stdio.h>
#include <stdint.h>

int main(void) {
  uint32_t size = 0;
  uint32_t response = 0;

  while (1) {
    puts("Добро пожаловать в игру!");
    puts("Какого размера поле ты хочешь себе?");
    fscanf(stdin, "%u", &size);
    if (size < 3) {
      puts("Слишком малый размер");
      continue;
    }
    if (size > 10) {
      puts("Слишком большой размер");
      continue;
    }
    
    TicTacToe game(size);
    game.Run();

    puts("Ещё партейку?");
    puts("1. Да");
    puts("2. Нет");
    fscanf(stdin, "%u", &response);
    if (response == 1) {
      continue;
    }
    if (response == 2) {
      break;
    }
  }
  return 0;
}