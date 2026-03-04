class Solution {
public:

    bool issafe(int i,int j,vector<vector<char>>& board,char num){

        for(int k=0;k<9;k++){
            if(board[i][k]==num) return false;
        }

        for(int k=0;k<9;k++){
            if(board[k][j]==num) return false;
        }

        int startRow = (i/3)*3;
        int startCol = (j/3)*3;

        for(int k=startRow;k<startRow+3;k++){
            for(int l=startCol;l<startCol+3;l++){
                if(board[k][l]==num) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j] == '.'){

                    for(char num = '1'; num <= '9'; num++){

                        if(issafe(i,j,board,num)){

                            board[i][j] = num;

                            if(solve(board)) 
                                return true;

                            board[i][j] = '.';  // backtrack
                        }
                    }

                    return false; // nothing worked
                }
            }
        }

        return true; // board completely filled
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};