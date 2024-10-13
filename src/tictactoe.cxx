#include "tictactoe.hxx"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TicTacToe::TicTacToe(int bSize) {
  this->boardSize = bSize;
  this->board = (int **)malloc(bSize * sizeof(int *));

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
      this->board[x][y] != 0)
    return false;
  this->board[x][y] = this->curPlayer ? 1 : 2; // 1 - крест, 2 - нуль
  this->curPlayer = !this->curPlayer;
  return true;
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
  for (size_t i = 0; i < this->boardSize; i++) {
    for (size_t j = 0; j < this->boardSize; j++) {
      printf("%d ", this->board[i][j]);
    }
    putc('\n', stdout);
  }
}