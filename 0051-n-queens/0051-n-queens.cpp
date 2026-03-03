class Solution {
public:

    bool check(vector<string>& help,int i,int j){

            int b=j;
        for(int a=i;a>=0;a--){
            if(b>=help.size())break;
            if(help[a][b]=='Q')return false;
            b++;
            
        }
        b=j;
        for(int a=i;a>=0;a--){
            if(b<0)break;
            if(help[a][b]=='Q')return false;
            b--;
            
        }
        return true;
    }
    void solve(vector<vector<string>>& result,int n,vector<bool>& col,int start,vector<string>& help){

            if(start==n){
                result.push_back(help);
                return;
            }

        
            for(int j=0;j<n;j++){
                if(col[j])continue;

                if(!check(help,start,j))continue;

                help[start][j]='Q';
                
                col[j]=true;
                solve(result,n,col,start+1,help);
                help[start][j]='.';
                
                col[j]=false;               

            }
        
    }
    vector<vector<string>> solveNQueens(int n) {



        vector<bool> col(n,false);
        vector<string> help(n, string(n, '.'));
        vector<vector<string>> result;

        solve(result,n,col,0,help);
        return result;
        
    }
};