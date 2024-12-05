// Программа на C++ для реализации игры в крестики-нолики
#include <iostream>
using namespace std;

// Функция для отрисовки игрового поля
void drawBoard(char board[3][3])
{
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
bool checkWin(char board[3][3], char player)
{
    // Проверка строк, столбцов и диагоналей
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player
            && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player
            && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player
        && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player
        && board[2][0] == player)
        return true;
    return false;
}

int main()
{
    // Инициализация поля и игроков
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };
    
    char player1, player2;
    cout << "Игрок 1, выберите символ (X или O): ";
    cin >> player1;
    
    // Проверим, чтобы игрок 2 получил противоположный символ
    player2 = (player1 == 'X') ? 'O' : 'X';
    cout << "Игрок 2, ваш символ: " << player2 << endl;

    char currentPlayer = player1; // Текущий игрок
    int row, col;
    int turn; // Объявляем переменную для количества ходов

    cout << "Добро пожаловать в Крестики-Нолики!\n";

    // Игровой цикл
    for (turn = 0; turn < 9; turn++) {
        // Отрисовка игрового поля
        drawBoard(board);

        // Запрос ввода
        while (true) {
            cout << "Игрок " << currentPlayer
                 << ", введите строку (0-2) и столбец (0-2): ";
            cin >> row >> col;

            if (board[row][col] != ' ' || row < 0 || row > 2
                || col < 0 || col > 2) {
                cout << "Неверный ход. Попробуйте снова.\n";
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
            break; // Выход из цикла после победы.
        }

        // Переключение на другого игрока
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    // Завершение игры
    drawBoard(board);

    // Проверка на ничью
    if (turn == 9 && !checkWin(board, player1) && !checkWin(board, player2)) {
        cout << "Ничья!\n";
    }

    return 0; // Выход из программы
}
