class Solution {
public:

    int solve(vector<int>& dp,vector<int>& nums,int i){

        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];

        // skip
        int res1=solve(dp,nums,i+1);
        // take
        int res2=nums[i]+solve(dp,nums,i+2);


        return dp[i]= max(res1,res2);
    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        vector<int> dp(n,-1);

       return solve(dp,nums,0);
        
    }
};