class Solution {
public:

bool is_safe(vector<vector<int>> &board,int n,int i,int j){
     
     // for col
     for(int k=0;k<i;k++){
        if(board[k][j]==1){
            return false;
        }
     }
     // upper-left-diagonal
     int l=j-1;
     for(int k=i-1;k>=0 && l>=0;k--){
        if(board[k][l]==1){
            return false;
        }
        l--;
     }
      // upper-right-diagonal
      l=j+1;
     for(int k=i-1;k>=0 && l<n;k--){
        if(board[k][l]==1){
            return false;
        }
        l++;
     }
     return true;
}

void solve(vector<vector<int>> &board,int &result,int n,int i){

   if(i==n){
    result++;
    return ;
   }

   for(int j=0;j<n;j++){
    if(is_safe(board,n,i,j)){
        board[i][j]=1;
        solve(board,result,n,i+1);
        board[i][j]=0;

    }
   }
    
}
    int totalNQueens(int n) {

        vector<vector<int>> board(n,vector<int>(n,0));
    int result=0;
        solve(board,result,n,0);
        return result;
        
    }
};