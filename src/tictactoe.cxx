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
  this->board[x][y] = this->curPlayer ? 1 : 0; // 1 - крест, 0 - нуль
  this->curPlayer = !this->curPlayer;
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