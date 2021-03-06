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
std::vector<int> newPassword;
bool Unlocked(int);
void DrawPasswordBoard();
void MainMenu();

const int M = 6;
const int N = 6;
char board[M][N];
char player_board[M][N];// 2d array with M rows and N columns // you can use vectors too
int numberOfHits;
int numberOfShots;
void PrintAIBoard();
void MakeBoard3(int);
void AIShoot();
bool AnyPlayerShipsLeft();
const char BLANK = ' ';
const char SHIP = 'S';
const char MISS = 'M';
const char HIT = 'H';
void QuitGame();
int letterToNumber(char);
int RandomRow();
int RandomColumn();
void MakeBoard(int);
void MakeBoardEmpty();
void WriteLetters();
void Shoot();
void WriteLetters();
void PrintBoard();
void PrintPlayerBoard();
void PlayBattleship();
void ChangePassword();
bool AnyShipsLeft();