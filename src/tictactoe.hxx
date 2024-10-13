#ifndef _TICTACTOE_H
#define _TICTACTOE_H

typedef class TicTacToe {
private:
  bool curPlayer;
  int **board;
  int boardSize;

public:
    TicTacToe(int bSize);
    ~TicTacToe();
    bool Move(int x, int y);
    bool CheckDraw();
    void Run();
} TicTacToe;

#endif