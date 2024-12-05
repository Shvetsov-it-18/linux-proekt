#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3; // Размер игрового поля

// Функция для вывода игрового поля
void printBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---------\n";
    }
    cout << "\n";
}

// Функция для проверки победы
bool checkWin(const vector<vector<char>>& board, char symbol) {
    // Проверяем строки и столбцы
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }

    // Проверяем диагонали
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }

    return false;
}