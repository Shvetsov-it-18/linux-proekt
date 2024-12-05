#include <iostream>
#include <vector>

using namespace std;
// Функция для проверки на ничью
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<vector<char>> board(SIZE, vector<char>(SIZE, ' ')); // Игровое поле
    char playerSymbol, opponentSymbol;
    char currentPlayer;

    cout << "Добро пожаловать в игру Крестики-Нолики!\n";

    // Выбор символа игрока
    while (true) {
        cout << "Выберите ваш символ (x или 0): ";
        cin >> playerSymbol;
        if (playerSymbol == 'x' || playerSymbol == '0') {
            opponentSymbol = (playerSymbol == 'x') ? '0' : 'x';
            break;
        }
        else {
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    }

    currentPlayer = playerSymbol; // Игрок начинает
    printBoard(board);

    while (true) {
        int row, col;
        cout << "Ход игрока " << currentPlayer << ". Введите строку и столбец (0-2): ";
        cin >> row >> col;

        // Проверка корректности ввода
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "Некорректный ход. Попробуйте снова.\n";
            continue;
        }

        // Обновляем поле
        board[row][col] = currentPlayer;
        printBoard(board);

        // Проверяем победу
        if (checkWin(board, currentPlayer)) {
            cout << "Игрок " << currentPlayer << " победил!\n";
            break;
        }

        // Проверяем ничью
        if (checkDraw(board)) {
            cout << "Ничья!\n";
            break;
        }

        // Смена игрока
        currentPlayer = (currentPlayer == playerSymbol) ? opponentSymbol : playerSymbol;
    }

    return 0;
}
