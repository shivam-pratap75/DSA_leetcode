// class Solution {
// public:
//     int operation(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
        
//         if(curr==nums.size()){
//             return 0;
//         }
//     if( dp[curr][prev+1]!=0){
//         return dp[curr][prev+1];
    
//     }
//         int include=0;
//         if(prev==-1 || nums[curr]>nums[prev]){

//             include=1+ operation(nums,curr+1,curr,dp);
//         }

//         int exclude=0+operation(nums,curr+1,prev,dp);

//         return dp[curr][prev+1]=max(include,exclude);
        
//     }
    
//     int lengthOfLIS(vector<int>& nums) {
//         vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,0));

//         return operation(nums,0,-1,dp);
        
//     }
// };


// bottom up DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); 
        
        int maxLIS = 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLIS = max(maxLIS, dp[i]);
        }
        
        return maxLIS;
    }
};