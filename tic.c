#include <stdio.h>
#include <stdbool.h>
void drawBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}
bool checkWin(char board[3][3], char player) {
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
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int row, col;
    printf("Welcome to Tic Tac Toe!\n");
    while (1) {
        printf("\nCurrent board:\n");
        drawBoard(board);
        printf("Player %c, enter row (0-2) and column (0-2) to place your marker: ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[row][col] = currentPlayer;
        if (checkWin(board, currentPlayer)) {
            printf("\nPlayer %c wins!\n", currentPlayer);
            drawBoard(board);
            break;
        }
        if (isBoardFull(board)) {
            printf("\nIt's a tie!\n");
            drawBoard(board);
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}