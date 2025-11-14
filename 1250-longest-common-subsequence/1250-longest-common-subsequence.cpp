class Solution {
public:

    int calculate(string &s1,string &s2,int i,int j,vector<vector<int>>& dp){

        if(i==s1.size() || j==s2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s1[i]==s2[j]){
            
            
           ans=1+ calculate(s1,s2,i+1,j+1,dp);
        }else{
            ans=max(calculate(s1,s2,i+1,j,dp),calculate(s1,s2,i,j+1,dp));
            


        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        
        int result=calculate(text1,text2,0,0,dp);
        return result;

        
    }
};