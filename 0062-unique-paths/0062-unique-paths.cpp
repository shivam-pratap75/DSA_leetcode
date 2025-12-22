// class Solution {
// public:
// int  solve(vector<vector<int>>dp,int i,int j,int& m, int& n){
//     if(i>=m || j>=n) return 0;

//     if(i == m-1 && j == n-1) return 1;

//     if(dp[i][j]!=-1)return dp[i][j];

//     // take_right
//         int take_right=solve(dp,i+1,j,m,n);


//     // take_down
//     int take_down=solve(dp,i,j+1,m,n);

//     return dp[i][j]=take_right + take_down;


// }
//     int uniquePaths(int m, int n) {

//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return solve(dp,0,0,m,n);
        
//     }
// };




//------------------TABULATION (BOTTOM_UP)-----------------//
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//        vector<vector<int>>dp(m,vector<int>(n,0));

//        for(int i=0;i<m;i++){
//         dp[i][0]=1;
//        }
//        for(int j=0;j<m;j++){
//         dp[0][j]=1;
//        }

//        for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//        }
//        return dp[m-1][n-1];
//     }
// };







class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // dp[j] represents ways from top (previous row's value)
                // dp[j-1] represents ways from left (current row's previous column)
                dp[j] = dp[j] + dp[j-1];
            }
        }
        
        return dp[n-1];
    }
};