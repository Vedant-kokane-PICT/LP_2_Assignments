#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int size;
    vector<int> queens; // queens[i] represents the column of the queen in row i

public:
    Solution(int n){
        size = n;
        queens = vector<int>(n,-1);
    }

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    void printBoard() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (queens[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    bool solveBranchAndBound(int row) {
        if (row == size) {
            // All queens are placed successfully
            printBoard();
            return true;
        }

        for (int col = 0; col < size; ++col) {
            if (isSafe(row, col)) {
                queens[row] = col;
                if (solveBranchAndBound(row + 1)) {
                    return true;
                }
                queens[row] = -1;
            }
        }
        return false;
    }


    void solve() {
        solveBranchAndBound(0);
    }
};

int main() {
    int n;
    cout << "Enter the size of chessboard -: ";
    cin >> n;
    Solution obj(n);
    obj.solve();
    return 0;
}


/*
Enter the size of chessboard - 8
Q . . . . . . . 
. . . . Q . . . 
. . . . . . . Q 
. . . . . Q . . 
. . Q . . . . . 
. . . . . . Q . 
. Q . . . . . . 
. . . Q . . . . 

*/
