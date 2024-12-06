#include <iostream>
#include <limits> // Для std::numeric_limits
using namespace std;

// Функция для отрисовки игрового поля
void drawBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Функция для проверки на победу
bool checkWin(char board[3][3], char player) {
    // Проверка строк, столбцов и диагоналей
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

int main() {
    setlocale(LC_ALL, "RU");
    // Инициализация поля и игроков
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };

    char player1, player2;
    cout << "Игрок 1, выберите символ (X или O): ";
    cin >> player1;

    // Проверим, чтобы игрок 2 получил противоположный символ
    player2 = (player1 == 'X' || player1 == 'x') ? 'O' : 'X';
    cout << "Игрок 2, ваш символ: " << player2 << endl;

    char currentPlayer = player1; // Текущий игрок
    int row, col;
    int turn; // Переменная для количества ходов

    cout << "Добро пожаловать в Крестики-Нолики!\n";

    // Игровой цикл
    for (turn = 0; turn < 9; turn++) {
        // Отрисовка игрового поля
        drawBoard(board);

        // Запрос ввода
        while (true) {
            cout << "Игрок " << currentPlayer << ", введите через пробел строку (1-3) и столбец (1-3): ";
            cin >> row >> col;

            // Проверка ввода на успешность
            if (cin.fail()) {
                cin.clear(); // Сбросить флаг ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорировать оставшийся ввод
                cout << "Неверный ввод. Пожалуйста, введите только числа.\n";
                continue; // Запросить ввод снова
            }

            // Приведение ввода к индексам массива (0-2)
            row--;
            col--;

            if (row < 0 || row > 2 || col < 0 || col > 2) {
                cout << "Неверные координаты. Укажите числа от 1 до 3.\n";
            }
            else if (board[row][col] != ' ') {
                cout << "Эта клетка уже занята. Попробуйте снова.\n";
            }
            else {
                break; // Корректный ввод, выходим из цикла.
            }
        }

        // Выполнение хода
        board[row][col] = currentPlayer;

        // Проверка на победу после выполнения хода
        if (checkWin(board, currentPlayer)) {
            drawBoard(board);
            cout << "Игрок " << currentPlayer << " победил!\n";
            return 0; // Выход из программы после победы.
        }

        // Переключение на другого игрока
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    // Завершение игры
    drawBoard(board);

    // Проверка на ничью
    cout << "Ничья!\n";
    return 0; // Выход из программы
}
