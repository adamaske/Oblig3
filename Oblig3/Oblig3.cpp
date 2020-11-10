// Oblig3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <conio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include "MyHeader.h"

int main()
{
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