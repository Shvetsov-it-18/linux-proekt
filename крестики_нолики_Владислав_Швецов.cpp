#include <iostream>
#include <vector>

using namespace std;
// ������� ��� �������� �� �����
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
    vector<vector<char>> board(SIZE, vector<char>(SIZE, ' ')); // ������� ����
    char playerSymbol, opponentSymbol;
    char currentPlayer;

    cout << "����� ���������� � ���� ��������-������!\n";

    // ����� ������� ������
    while (true) {
        cout << "�������� ��� ������ (x ��� 0): ";
        cin >> playerSymbol;
        if (playerSymbol == 'x' || playerSymbol == '0') {
            opponentSymbol = (playerSymbol == 'x') ? '0' : 'x';
            break;
        }
        else {
            cout << "������������ �����. ���������� �����.\n";
        }
    }

    currentPlayer = playerSymbol; // ����� ��������
    printBoard(board);

    while (true) {
        int row, col;
        cout << "��� ������ " << currentPlayer << ". ������� ������ � ������� (0-2): ";
        cin >> row >> col;

        // �������� ������������ �����
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "������������ ���. ���������� �����.\n";
            continue;
        }

        // ��������� ����
        board[row][col] = currentPlayer;
        printBoard(board);

        // ��������� ������
        if (checkWin(board, currentPlayer)) {
            cout << "����� " << currentPlayer << " �������!\n";
            break;
        }

        // ��������� �����
        if (checkDraw(board)) {
            cout << "�����!\n";
            break;
        }

        // ����� ������
        currentPlayer = (currentPlayer == playerSymbol) ? opponentSymbol : playerSymbol;
    }

    return 0;
}
