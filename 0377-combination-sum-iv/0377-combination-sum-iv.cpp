class Solution {
public:
    int solve(vector<int>& nums,int target,vector<int>& dp){

            if(target<0)return 0;

            if(target==0){
                return 1;
            }
            if(dp[target]!=-1)return dp[target];

            int count=0;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];

           count+= solve(nums,target-num,dp);

        }
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {

        
        vector<int>dp(target+1,-1);
       return solve(nums,target,dp);
       
        
    }
};