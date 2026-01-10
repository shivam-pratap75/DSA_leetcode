class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>>& dp) {
        int n = s1.size();
        int m = s2.size();

        // If s1 is exhausted, delete remaining s2 chars
        if (i == n) {
            int sum = 0;
            for (int k = j; k < m; k++) sum += s2[k];
            return sum;
        }

        // If s2 is exhausted, delete remaining s1 chars
        if (j == m) {
            int sum = 0;
            for (int k = i; k < n; k++) sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        // If characters match
        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1, dp);
        }

        // Delete from s1 or s2
        int deleteS1 = s1[i] + solve(s1, s2, i + 1, j, dp);
        int deleteS2 = s2[j] + solve(s1, s2, i, j + 1, dp);

        return dp[i][j] = min(deleteS1, deleteS2);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s1, s2, 0, 0, dp);
    }
};
