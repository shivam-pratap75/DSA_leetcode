class Solution {
public:

    int solve(string& word1,string& word2,vector<vector<int>>&dp,int i,int j){
        int n=word1.size();
        int m=word2.size();

        if(i==n) return m-j;
        if(j==m) return n-i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j]=solve(word1,word2,dp,i+1,j+1);
        }

        int delete1= 1+solve(word1,word2,dp,i+1,j);
        int delete2= 1+solve(word1,word2,dp,i,j+1);

        return dp[i][j] = min(delete1,delete2);

        
    }
    int minDistance(string word1, string word2) {

        int n=word1.size();
        int m=word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(word1,word2,dp,0,0);
        
    }
};