class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || i>=n)return;
        if(j<0 || j>=m)return;


        if(grid[i][j]=='0')return ;

        if(grid[i][j]=='1')grid[i][j]='0';
        dfs(grid,i+1,j); 
         dfs(grid,i-1,j); 
         dfs(grid,i,j+1);
         dfs(grid,i,j-1);
    

    }
    int numIslands(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

            int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    result++;
                    dfs(grid,i,j);
                }
            }
        }

            return result;    
    }
};