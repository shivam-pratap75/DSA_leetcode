class Solution {
public:

    int n;
 int operation(int i,int remain,vector<int>& cost, vector<int>& time,vector<vector<int>>&dp){

    if(remain<=0){
        return 0;
    }

    if(i>=n){
        return 1e9;
    }
    if(dp[i][remain]!=-1) return dp[i][remain];

    int paint_i=cost[i]+operation(i+1,remain-1-time[i],cost,time,dp);
    int not_paint_i=operation(i+1,remain,cost,time,dp);
    return dp[i][remain]=min(paint_i,not_paint_i);
    
 }
    int paintWalls(vector<int>& cost, vector<int>& time) {

        vector<vector<int>>dp(501,vector<int>(501,-1));

      n=cost.size();
      return  operation(0,n,cost,time,dp);


        
    }
};