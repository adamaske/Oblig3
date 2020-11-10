#pragma once
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

const int p_width = 5;
const int p_height = 5;
int p_x = 0;
int p_y = 0;
std::vector<int> enterdPassword;
std::vector<int> correctPassword;
bool Unlocked(int);
void DrawPasswordBoard();
void MainMenu();