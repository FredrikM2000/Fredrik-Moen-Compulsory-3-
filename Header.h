#pragma once

const int M = 6;//Number of rows
const int N = 6;//number of columns
char blank = ' ';

char board[N][M] = {0};

int shots_taken = 2;
const int hitSize = 10;
int hitX[hitSize] = {3,6};
int hitY[hitSize] = {2,5};

