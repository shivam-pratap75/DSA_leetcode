class Solution {
public:

    int operation(int i,int j,vector<int>& nums,vector<vector<int>>& dp){

        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int include_i = nums[i] + min(operation(i+2,j,nums,dp),operation(i+1,j-1,nums,dp));

        int include_j=nums[j] + min(operation(i+1,j-1,nums,dp),operation(i,j-2,nums,dp));

   return dp[i][j]=max(include_i,include_j);
    }
    bool predictTheWinner(vector<int>& nums) {

        
        int n=nums.size();
        vector<vector<int>>  dp(n,vector<int>(n,-1));
        int total_score=accumulate(nums.begin(),nums.end(),0);

        int player1_score=operation(0,n-1,nums,dp);
        int player2_score=total_score-player1_score;

        if(player1_score>=player2_score){
            return true;
        }else{
            return false;
        }
        
    }
};