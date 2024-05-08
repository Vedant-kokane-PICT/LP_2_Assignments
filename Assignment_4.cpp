#include<bits/stdc++.h>
using namespace std;


class NQueens{
	int size;
	vector<vector<string>> ans;
public:
	NQueens(int n){
		size = n;
	}
	
	void solve(){
		vector<string> board(size);
		string s(size,'.');
		for(int i=0;i<size;i++){
			board[i] = s;
		}
		vector<bool> rowLeft(size,0);
		vector<bool> lowerDiagonal(2 * size - 1,0);
		vector<bool> upperDiagonal(2 * size - 1,0);

		helper(0,board,rowLeft,lowerDiagonal,upperDiagonal);

		print();
	}

	void helper(int col,vector<string> &board,vector<bool> &rowLeft,vector<bool> &lowerDiagonal,vector<bool> &upperDiagonal){
		if(col == size){
			ans.push_back(board);
			return;
		}

		for(int row = 0;row<size ;row++){
			if(rowLeft[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[(size-1) + (col-row)] == 0){
				board[row][col] = 'Q';
				rowLeft[row] = 1;
				lowerDiagonal[row+col] = 1;
				upperDiagonal[(size-1) + (col-row)] = 1;
				helper(col+1,board,rowLeft,lowerDiagonal,upperDiagonal);
				board[row][col] = '.';
				rowLeft[row] = 0;
				lowerDiagonal[row+col] = 0;
				upperDiagonal[(size-1) + (col-row)] = 0;
			}
		}
	}

	void print() {
        if (ans.empty()) {
            cout << "No solution found." << endl;
            return;
        }
        for (auto sol:ans[0]) {
            for (auto x : sol) {
                cout << x << " ";
            }
            cout << endl;
        }
    }


};


int main(){
    int n;
    cout<<"Enter the size of chessboard - "<<endl;
    cin>>n;
	NQueens object(n);
	object.solve();
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
