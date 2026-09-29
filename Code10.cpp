//Implement N Queen's problem using Back Tracking.

#include <bits/stdc++.h>
using namespace std;

//Function 1 :- Check whether queen can be placed
bool isSafe(vector<vector<int>> &board, int row, int col, int n) {

    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

//Function 2 :- Print the board
void printBoard(vector<vector<int>> &board, int n, int solution) {
    cout << "Solution " << solution << ":" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//Function 3:- Place queens using backtracking
int placeQueens(vector<vector<int>> &board, int row, int n, int &solution) {
    if (row == n) {
        solution++;
        printBoard(board, n, solution);
        return 1;
    }

    int count = 0;

    //Try every column
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // Place queen

            // Place queen in next row
            count += placeQueens(board, row + 1, n, solution);

            board[row][col] = 0; // Backtrack
        }
    }

    return count;
}

int main(){
    int n;
    cout<<"Enter the number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    int solution = 0;

    int totalSolutions = placeQueens(board,0,n,solution);

    if(totalSolutions == 0){
        cout<<"No solution exists for "<<n<<" queens."<<endl;
    } else {
        cout<<"Total solutions for "<<n<<" queens: "<<totalSolutions<<endl;
    }

    return 0;
}