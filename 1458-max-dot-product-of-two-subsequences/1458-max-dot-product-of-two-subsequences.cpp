class Solution {
public:

    int solve(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){

        int n=nums1.size();
        int m=nums2.size();

        if(i==n || j==m) return -1e9;;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi=nums1[i]*nums2[j];

        int take= maxi+solve(nums1,nums2,i+1,j+1,dp);
        int not_take=solve(nums1,nums2,i+1,j,dp);
        int not_take2=solve(nums1,nums2,i,j+1,dp);

        maxi=max(maxi,max(take,max(not_take,not_take2)));

        return dp[i][j]=maxi;



    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n=nums1.size();
        int m=nums2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(nums1,nums2,0,0,dp);
        
    }
};