#pragma once
#include <stdlib.h>

bool validateRow(int Board[9][9], int row);
bool validateCol(int Board[9][9], int col);
bool validateSubMatrix(int Board[9][9], int row, int col);
bool validateBoard(int Board[9][9]);

void generateBoard(int Board[9][9])
{
    int row, col, num;

    int hints = rand() % 9 + 17;

    for(int i = 0; i < hints; i++)
    {
        do
        {
            row = rand() % 9;
            col = rand() % 9;
            num = rand() % 9 + 1;

            if(Board[row][col] == 0)
                Board[row][col] = num;
            if (!validateRow(Board, row) || !validateCol(Board, col) || !validateSubMatrix(Board, (row/3) * 3, (col/3) * 3)) {
                Board[row][col] = 0;
            }
        } while(Board[row][col] == 0);
        
    }
}

bool validateRow(int Board[9][9], int row)
{
    int occ[9] = {0};

    for(int i = 0; i < 9; i++)
    {
        if(Board[row][i] == 0)
            continue;

        if(occ[Board[row][i] - 1] == 1)
            return false;

        occ[Board[row][i] - 1]++;
    }

    return true;
}

bool validateCol(int Board[9][9], int col)
{
    int occ[9] = {0};

    for(int i = 0; i < 9; i++)
    {
        if(Board[i][col] == 0)
            continue;

        if(occ[Board[i][col] - 1] == 1)
            return false;

        occ[Board[i][col] - 1]++;
    }

    return true;
}

bool validateSubMatrix(int Board[9][9], int row, int col)
{
    int occ[9] = {0};

    for(int i = row; i < row + 3; i++)
    {
        for(int j = col; j < col + 3; j++)
        {
            if(Board[i][j] == 0)
                continue;

            if(occ[Board[i][j] - 1] == 1)
                return false;

            occ[Board[i][j] - 1]++;
        }
    }

    return true;
}

bool validateBoard(int Board[9][9])
{
    for(int i = 0; i < 9; i++)
        if(!validateRow(Board, i) || !validateCol(Board, i) || !validateSubMatrix(Board, i / 3 * 3, i % 3 * 3))
            return false;

    return true;
}