// class Solution {
// public:

//     int solve(vector<int>& nums,int i,int j,vector<vector<int>>& dp,int& k){
//         if(i>j)return 0;

        
//         if(dp[i][j]!=-1)return dp[i][j];
//         if((long long)nums[i] *k>=nums[j])return (j-i+1);
//         // skip first 
//         int first=solve(nums,i+1,j,dp,k);

//         // skip last 
//         int last=solve(nums,i,j-1,dp,k);

//     return dp[i][j]=max(first,last);
        
//     }
//     int minRemoval(vector<int>& nums, int k) {

//         sort(nums.begin(),nums.end());
//         int n=nums.size();
//         int j=n-1;
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//        int result= solve(nums,0,j,dp,k);
//         return (n-result);
//     }
// };

class Solution {
public:

   
    int minRemoval(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int result=0;

        for(int right=0;right<n;right++){
            while(left <=right && (long long)nums[left] *k<nums[right]){
                left++;
            }
            result=max(result,right-left+1);
        }

        return n-result;
    }
};