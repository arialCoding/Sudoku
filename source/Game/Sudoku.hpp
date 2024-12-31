#pragma once


void generateBoard(int Board[9][9]);

bool validateRow(int Board[9][9], int row);
bool validateCol(int Board[9][9], int col);
bool validateSubMatrix(int Board[9][9], int row, int col);

bool validateBoard(int Board[9][9]);
bool boardFull(int board[9][9]);
