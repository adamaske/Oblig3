// Oblig3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include "MyHeader.h"

int main()
{
    srand(time(0));
    if (Unlocked(3)) {
        MainMenu();
    }
    else {
        std::cout << "\nWrong password! Bye!\n";
    }
    return 0;
}

void MainMenu() {
    system("cls");
    std::cout << "Welcome to Battleship!\n\n";

    std::cout << "1.Change Password\n2.Play Battleship!\n3.Quit";

    char input = _getch();
    switch (input) {
    case '1':
        ChangePassword();
        break;
    case '2':
        PlayBattleship();
        break;
    case '3':
        QuitGame();
        break;
    default:
        MainMenu();
        break;
    }
}

void QuitGame() {
    std::exit;
}

void ChangePassword() {
    p_x = 0;
    p_y = 0;
    std::cout << "Enter your new password, [Enter] to comfirm!\n";

    while (true) {
        DrawPasswordBoard();
        auto input = _getch();
        if (input == 224) {
            switch (_getch()) {
            case KEY_UP:
                if (p_x - 1 >= 0) {
                    newPassword.push_back(KEY_UP);
                    p_x--;
                }
                break;
            case KEY_DOWN:
                if (p_x + 1 <= 4) {
                    newPassword.push_back(KEY_DOWN);
                    p_x++;
                }
                break;
            case KEY_RIGHT:
                if (p_y + 1 <= 4) {
                    newPassword.push_back(KEY_RIGHT);
                    p_y++;
                }
                break;
            case KEY_LEFT:
                if (p_y - 1 >= 0) {
                    newPassword.push_back(KEY_LEFT);
                    p_y--;
                }
                break;
            }
        }
        else if (input == '\r') {
            //Check if its correct
            //Create vector of correct password
            std::fstream passwordFile("password.txt", std::ios::out);

            for (int i = 0; i < newPassword.size()-1; i++)
            {
                passwordFile << newPassword[i] << std::endl;
            }
            std::cout << "\nYou have changed your password!\n\nPress any key to return to Main Menu...";
            if (_getch()) {
                MainMenu();
            }
        }
    }

}

bool Unlocked(int attempts) {

    //If there exists a password file, ask for it, else create a new
    std::fstream passwordFile("password.txt", std::ios::in);
    if (passwordFile) {
        std::cout << "Found password file";
        for (int i = 0; i < attempts; i++)
        {
            while (true) {
            system("cls");
            std::cout << "Please enter you password, attempts left: " << attempts - i << "\n";
            DrawPasswordBoard();
            auto input = _getch();
            if (input == 224) {
                switch (_getch()) {
                case KEY_UP:
                    if (p_x - 1 >= 0) {
                        enterdPassword.push_back(KEY_UP);
                        p_x--;
                    }
                    break;
                case KEY_DOWN:
                    if (p_x + 1 <= 4) {
                        enterdPassword.push_back(KEY_DOWN);
                        p_x++;
                    }
                    break;
                case KEY_RIGHT:
                    if (p_y + 1 <= 4) {
                        enterdPassword.push_back(KEY_RIGHT);
                        p_y++;
                    }
                    break;
                case KEY_LEFT:
                    if (p_y - 1 >= 0) {
                        enterdPassword.push_back(KEY_LEFT);
                        p_y--;
                    }
                    break;
                }
            }
            else if (input == '\r') {
                //Check if its correct
                //Create vector of correct password
                
                while (!passwordFile.eof()) {
                    std::string j;
                    std::getline(passwordFile, j);
                    std::istringstream ss(j);
                    int p;
                    ss >> p;
                    correctPassword.push_back(p);
                }
                /*
                std::cout << "\nYou entered: ";
                for (int t = 0; t <enterdPassword.size(); t++)
                {
                    std::cout << enterdPassword[t] << ", ";
                }*/
                if (enterdPassword != correctPassword) {
                    return false;
                }
                else {
                    return true;
                }
            }
            }            
        }
    }else {
        //No password exists
        std::vector<int> newPassword;
        
        std::cout << "\nWritten: ";
        while (true) {
            system("cls");
            std::cout << "Create a new password, [Enter] to comfirm.\n";
            DrawPasswordBoard();
            auto input = _getch();
            if (input == 224) {
                switch (_getch()) {
                case KEY_UP:
                    if (p_x - 1 >= 0) {
                        newPassword.push_back(KEY_UP);
                        p_x--;
                    }
                    break;
                case KEY_DOWN:
                    if (p_x + 1 <= 4) {
                        newPassword.push_back(KEY_DOWN);
                        p_x++;
                    }
                    break;
                case KEY_RIGHT:
                    if (p_y + 1 <= 4) {
                        newPassword.push_back(KEY_RIGHT);
                        p_y++;
                    }
                    break;
                case KEY_LEFT:
                    if (p_y - 1 >= 0) {
                        newPassword.push_back(KEY_LEFT);
                        p_y--;
                    }
                    break;
                }
            }
            else if (input == '\r') {
                //Password to file
                std::fstream newPasswordFile("password.txt", std::ios::out);
                for (int i = 0; i < newPassword.size()-1; i++)
                {
                    newPasswordFile << newPassword[i] << std::endl;
                }
                return true;
            }
        }
    }
    return true;
}

void DrawPasswordBoard() {
    for (int i = 0; i < p_height; i++)
    {
        for (int k = 0; k < p_width; k++)
        {
            if (i == p_x && k == p_y) {
                std::cout << "*" << "|";
            }
            else {
                std::cout << i + k << "|";
            }
            
        }
        std::cout << "\n";
    }
}

void PlayBattleship() 
{
    numberOfShots = 13;
    MakeBoardEmpty();
    MakeBoard(10);
    Shoot();
}
void Shoot() {
    
    while (numberOfShots > 0) {
        system("cls");

        std::cout << "What cell do you want to shoot at?    Format [Letter][Number], for example press [a] than [1]\n";
        std::cout << "Shots left: " << numberOfShots << "\nShips hit: " << numberOfHits<<"\n";
        PrintPlayerBoard();
        std::cout << "\nYour shot: ";
        char _a = _getch();
        _a = toupper(_a);
        std::cout << _a;
        int a = letterToNumber(_a);
        char _b = _getch();
        int b = _b - '0';
        b = b - 1;
        std::cout << b+1;
        if (board[b][a] == SHIP) {
            board[b][a] = HIT;
            numberOfHits++;
        }
        else if (board[b][a] == BLANK) {
            board[b][a] = MISS;
        }
        numberOfShots--;
        if (!AnyShipsLeft()) {
            system("cls");
            std::cout << "Game Won!\n\nYou all ships with only" << numberOfShots << " shots this round!";
            PrintBoard();
            std::cout << "\n\nPress any key to return to MainMenu...";
        }
    }
    if (!AnyShipsLeft) {
        system("cls");
        std::cout << "Game Won!\n\nYou all ships with only" << numberOfShots << " shots this round!";
        PrintBoard();
        std::cout << "\n\nPress any key to return to MainMenu...";
    }
    else {
        system("cls");
        std::cout << "Game Over!\n\nYou hit " << numberOfHits << " ships this round!";
        std::cout << "\n\nPress any key to return to MainMenu...";
        if (_getch()) {
            MainMenu();
        }
    }
    
}
bool AnyShipsLeft() {
    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < N; k++)
        {
            if (board[i][k] == SHIP) {
                return true;
            }
        }
    }
    return false;
}

void PrintBoard() {
    std::cout <<"\n\n";
    for (int i = 0; i < M; i++)
    {
        std::cout << i+1 << "|";
        for (int k = 0; k < N; k++)
        {
            std::cout<< board[i][k] << "|";
        }
        std::cout << "\n";
    }
    WriteLetters();
}

void PrintPlayerBoard() {
    for (int i = 0; i < M; i++)
    {
        std::cout << i+1 << "|";
        for (int k = 0; k < N; k++)
        {
            //Dont print if its a ship;
            if (board[i][k] != SHIP) {
                std::cout << board[i][k] << "|";
            }
            else {
                std::cout << ' ' << "|";
            }
            
        }
        std::cout << "\n";
    }
    WriteLetters();
}

void MakeBoardEmpty() {
    for (int i = 0; i < M; i++)
    {
        for (int k = 0; k < N; k++)
        {
            board[i][k] = BLANK;
        }
    }
}

void MakeBoard(int numberOfShips) {
    int count = 0;
    while (count < numberOfShips) {
        int xpos = RandomRow();
        int ypos = RandomColumn();

        if (board[xpos][ypos] == BLANK) {
            board[xpos][ypos] = SHIP;
            count++;
        }
    }
}

int letterToNumber(char letter) // only big letters
{
    return static_cast<int>(letter) - 65;
}

int RandomRow() {
    return rand() % M;
}
int RandomColumn() {
    return rand() % N;
}
void WriteLetters() {
    std::cout << " |";
    for (int i = 0; i < N; i++)
    {
        char x = i + 'A';
        std::cout << x << "|";
    }
}