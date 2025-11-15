// class Solution {
// public:
//     int operation(string word1,string word2,int i,int j,vector<vector<int>>&dp){

//         if(i==word1.length()){
//             return word2.length()-j;
//         }
//         if(j==word2.length()){
//             return word1.length()-i;
//         }
//          if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         int ans=0;
//         if(word1[i]==word2[j]){
//             return dp[i][j]=operation(word1,word2,i+1,j+1,dp);
//         }else{
//             int insert= 1+operation(word1,word2,i,j+1,dp);
//             int del= 1+operation(word1,word2,i+1,j,dp);
//             int replace = 1+operation(word1,word2,i+1,j+1,dp);
//          ans=min(insert,min(del,replace));
            
//         }
//        return dp[i][j]= ans;

//     }
//     int minDistance(string word1, string word2) {
//         vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));

//         return operation(word1,word2,0,0,dp);
        
//     }
// };

class Solution {
public:
  
    int minDistance(string word1, string word2) {
         vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));

    for(int j=0;j<=word2.length();j++){

        dp[word1.length()][j]=word2.length()-j;
    }
     for(int i=0;i<=word1.length();i++){

        dp[i][word2.length()]=word1.length()-i;
    }

    for(int i=word1.size()-1;i>=0;i--){
        for(int j=word2.size()-1;j>=0;j--){
            int ans=0;
            if(word1[i]==word2[j]){
                ans=dp[i+1][j+1];
            }else{
                int insert=1+dp[i][j+1];
                int del=1+dp[i+1][j];
                int replace=1+dp[i+1][j+1];
                ans=min(insert,min(del,replace));
            }
            dp[i][j]=ans;
        }

        
    }
return dp[0][0];
        
    }
};