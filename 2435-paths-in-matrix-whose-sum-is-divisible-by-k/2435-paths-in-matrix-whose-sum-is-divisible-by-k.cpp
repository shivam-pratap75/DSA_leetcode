class Solution {
public:
const int  mod=1e9+7;
int solve(int i,int j,int sum,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
     int n=grid.size();
    int m=grid[0].size();

    if(i==n || j==m) return 0;
    if(i==n-1 && j==m-1){
        sum = (sum + grid[i][j]) % k;
            if (sum == 0) {
                return 1;
            }

            return 0;
    }
    if(dp[i][j][sum]!=-1)  return dp[i][j][sum];

    // j+=1
    int increase_j=solve(i,j+1,(sum+grid[i][j])%k,k,grid,dp);
    //i+=1
    int increase_i=solve(i+1,j,(sum+grid[i][j])%k,k,grid,dp);

    return dp[i][j][sum]= (increase_j + increase_i) % mod;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));

        int result=0;
        return  solve(0,0,0,k,grid,dp);
       
    }
};