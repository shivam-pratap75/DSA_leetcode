class Solution {
public:
    int solve(vector<int>& nums, int i, int remainder, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return (remainder == 0) ? 0 : INT_MIN;
        }
        
        if (dp[i][remainder] != -1) {
            return dp[i][remainder];
        }
        
        // Option 1: Don't take current element
        int not_take = solve(nums, i + 1, remainder, dp);
        
        // Option 2: Take current element
        int take = nums[i] + solve(nums, i + 1, (remainder + nums[i]) % 3, dp);
        
        return dp[i][remainder] = max(not_take, take);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(nums, 0, 0, dp);
    }
};