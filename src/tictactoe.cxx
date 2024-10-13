#include "tictactoe.hxx"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TicTacToe::TicTacToe(int bSize) {
  this->boardSize = bSize;
  this->board = (int **)malloc(bSize * sizeof(int *));
  this->curPlayer = true;
  this->gameOver = false;

  for (size_t i = 0; i < this->boardSize; i++) {
    this->board[i] = (int *)malloc(bSize * sizeof(int));
    memset(this->board[i], 0, sizeof(int));
  }
}

TicTacToe::~TicTacToe() {
  for (size_t i = 0; i < this->boardSize; i++)
    free(this->board[i]);
  free(this->board);
}

bool TicTacToe::Move(int x, int y) {
  if ((x > this->boardSize || x < 0) || (y > this->boardSize || y < 0) ||
      this->board[y - 1][x - 1] != 0)
    return false;
  this->board[y - 1][x - 1] = this->curPlayer ? 1 : -2; // 1 - нуль, -2 - крест
  this->curPlayer = !this->curPlayer;
  return true;
}

void TicTacToe::ShowBoard() {
  for (size_t i = 0; i < this->boardSize; i++) {
    for (size_t j = 0; j < this->boardSize; j++) {
      switch (this->board[i][j]) {
      case 1:
        putc('O', stdout);
        break;
      case -2:
        putc('X', stdout);
        break;
      default:
        putc('[', stdout);
        putc(']', stdout);
      }
      putc(' ', stdout);
    }
    putc('\n', stdout);
  }
  putc('\n', stdout);
}

int TicTacToe::CheckWin() {
  int sum = 0;
  for (size_t i = 0; i < this->boardSize; i++) {
    for (size_t j = 0; j < this->boardSize; j++) {
      sum += this->board[i][j];
    }
    if (sum == (this->boardSize))
      return 0;
    if (sum == (this->boardSize * 2))
      return 1;
  }
  sum = 0;

  for (size_t i = 0; i < this->boardSize; i++) {
    sum += this->board[i][i];
  }
  if (sum == (this->boardSize))
    return 0;
  if (sum == (this->boardSize * 2))
    return 1;

  sum = 0;

  for (size_t i = this->boardSize; i > -1; i--) {
    for (size_t j = 0; j < this->boardSize; j++) {
      sum += this->board[i][j];
    }
  }
  if (sum == (this->boardSize))
    return 0;
  if (sum == (this->boardSize * 2))
    return 1;

  return -1;
}

bool TicTacToe::CheckDraw() {
  for (size_t i = 0; i < this->boardSize; i++)
    for (size_t j = 0; j < this->boardSize; j++)
      if (this->board[i][j] == 0)
        return false;
  return true;
}

void TicTacToe::Run() {
  int x = 0, y = 0;
  int winner = 0;
  while (!this->gameOver) {
    printf("Сейчас ходит игрок: ");
    if (this->curPlayer)
      printf("%c\n", 'O');
    else
      printf("%c\n", 'X');

    ShowBoard();

    while (1) {
      printf("Введи координату по X (от 0 до %d): ", this->boardSize - 1);
      fscanf(stdin, "%d", &x);
      printf("Введи координату по Y (от 0 до %d): ", this->boardSize - 1);
      fscanf(stdin, "%d", &y);
      if (this->Move(x, y))
        break;
    }

    winner = CheckWin();
    if (winner == -1) {
      puts("Ничья!");
      break;
    }

    if (winner == 0) {
      printf("Победил %c", 'O');
      break;
    }

    if (winner == 1) {
      printf("Победил %c", 'X');
      break;
    }
  }
}