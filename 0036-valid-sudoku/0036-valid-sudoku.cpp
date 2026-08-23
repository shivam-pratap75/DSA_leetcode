class Solution {
public:

    bool check_box(int i, int j,vector<vector<char>>& board){
        
        unordered_map<char,int> temp;
        for(int n=i;n<i+3;n++){
            for(int m=j;m<j+3;m++){
                if(board[n][m] == '.') continue;
                temp[board[n][m]]++;

                if(temp[board[n][m]]>=2){
                    return false;
                }
            }
        }
        return true;
    }

    bool check_row(int i,vector<vector<char>>& board){

             unordered_map<char,int> temp;
            for(int n=0;n<=8;n++){
                if(board[i][n] == '.') continue;
                temp[board[i][n]]++;
                 if(temp[board[i][n]]>=2){
                    return false;
                }
            }
    return true;
    }

    bool check_col( int j,vector<vector<char>>& board){

         unordered_map<char,int> temp;
            for(int n=0;n<=8;n++){
                if(board[n][j] == '.') continue;
                temp[board[n][j]]++;
                 if(temp[board[n][j]]>=2){
                    return false;
                }
            }
    return true;

    }

    bool isValidSudoku(vector<vector<char>>& board) {

           

        for(int i=0;i<9;i++){
            if(!check_col(i,board))return false;
            if(!check_row(i,board))return false;

            int k=(i/3)*3;
            int l=(i%3)*3;
            if(!check_box(k,l,board))return false;
        }
        return true;
    }
};