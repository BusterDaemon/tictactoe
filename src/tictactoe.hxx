#ifndef _TICTACTOE_H
#define _TICTACTOE_H

typedef class TicTacToe {
private:
  bool curPlayer;
  bool gameOver;
  int **board;
  int boardSize;

public:
    TicTacToe(int bSize);
    ~TicTacToe();
    bool Move(int x, int y);
    int CheckWin();
    bool CheckDraw();
    void Run();
} TicTacToe;

#endif