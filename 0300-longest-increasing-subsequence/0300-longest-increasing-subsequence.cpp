class Solution {
public:
    int operation(vector<int>& nums,int curr,int prev,vector<vector<int>>& dp){
        
        if(curr==nums.size()){
            return 0;
        }
    if( dp[curr][prev+1]!=0){
        return dp[curr][prev+1];
    
    }
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev]){

            include=1+ operation(nums,curr+1,curr,dp);
        }

        int exclude=0+operation(nums,curr+1,prev,dp);

        return dp[curr][prev+1]=max(include,exclude);
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,0));

        return operation(nums,0,-1,dp);
        
    }
};