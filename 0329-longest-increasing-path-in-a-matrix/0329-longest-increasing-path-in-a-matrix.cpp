class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j] != 0) return dp[i][j];
        int maxLen = 1;
        for (auto &dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(x, y, matrix, dp));
            }
        }
        return dp[i][j] = maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                res = max(res, dfs(i, j, matrix, dp));
        return res;
    }
};