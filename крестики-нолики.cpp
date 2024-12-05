#include <iostream>

const int SIZE = 3; // Размер игрового поля
char board[SIZE][SIZE]; // Игровое поле
using namespace std;
// Инициализация игрового поля
void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' '; // Пустое поле
        }
    }
}
// Вывод игрового поля
void displayBoard() {
    cout << "Текущий статус игрового поля:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | "; // Разделители
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---------\n"; // Разделительные линии
    }
}
// Проверка на победу
bool checkWin(char player) {
    // Проверка строк и столбцов
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Проверка диагоналей
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
// Проверка заполненности поля
bool isBoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}
// Обработка хода
bool makeMove(int row, int col, char player) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}
// Основная функция игры
int main() {
    initializeBoard(); // Инициализация игрового поля
    char player = 'X'; // Символ текущего игрока
    int row, col;
    while (true) {
        displayBoard(); // Вывод текущего состояния поля
        cout << "Игрок " << player << ", введите строку и столбец (0-2): ";
        cin >> row >> col;
        // Если ход успешен
        if (makeMove(row, col, player)) {
            // Проверка на победу
            if (checkWin(player)) {
                displayBoard(); // Вывод финального поля
                cout << "Игрок " << player << " выиграл!\n";
                break;
            } else if (isBoardFull()) { // Проверка на ничью
                displayBoard(); // Вывод финального поля
                cout << "Ничья!\n";
                break;
            }
            // Смена игрока
            player = (player == 'X') ? 'O' : 'X';
        } else {
            cout << "Неверный ход. Попробуйте снова.\n";
        }
    }
    return 0; // Выход из программы
}
