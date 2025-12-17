class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        
        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }
        
        
        if (i >= m || j >= n) {
            return INT_MAX;
        }
        
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        
        int take_right = solve(grid, dp, i, j + 1);  
        int take_down = solve(grid, dp, i + 1, j);   
        

        int minPath = min(take_right, take_down);
        

        dp[i][j] = grid[i][j] + minPath;
        
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return solve(grid, dp, 0, 0);
    }
};