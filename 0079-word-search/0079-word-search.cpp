class Solution {
public:

    bool solve(vector<vector<char>>& board,string word,int x,int i,int j){
        if(word.length()==x)return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())return false;

        if(word[x]!=board[i][j])return false;
        char temp=board[i][j];
        board[i][j]='1';

        bool up=solve(board,word,x+1,i-1,j);
        bool down=solve(board,word,x+1,i+1,j);
        bool right=solve(board,word,x+1,i,j+1);
        bool left=solve(board,word,x+1,i,j-1);
        board[i][j]=temp;
        return (up || down || right || left) ? true :false;
    }
    bool exist(vector<vector<char>>& board, string word) {

       
        int n=board.size();
        int m=board[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
                 bool check=solve(board,word,0,i,j);
              if(check==true)return true;
            }

            
        }
       }
       return false; 
    }
};