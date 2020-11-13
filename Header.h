#pragma once
#include <vector>
const int M = 6;//Number of rows
const int N = 6;//number of columns
char blank = ' ';

char board[N][M] = {0};

const char SHIP = 'S';

int ships = 20;

std::vector <int> shipX = {};
std::vector <int> shipY = {};

int hits = 0;
std::vector <int> hitX = {};
std::vector <int> hitY = {};

int misses = 0;
std::vector <int> missX = {};
std::vector <int> missY = {};

int shots = 5;