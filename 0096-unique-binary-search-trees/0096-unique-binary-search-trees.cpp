class Solution {
public:
    int c(int x,int dp[]){
        
        if(x==0 || x==1) return 1;
        if(dp[x]!=-1){
            return dp[x];
        }
        int res=0;
        for(int i=1;i<=x;i++){
        res+=c(x-i,dp)*c(i-1,dp);
        }
        dp[x]=res;

        return res; 
    }
    int numTrees(int n) {
        int dp[n+1];
        for(int i=1;i<=n;i++) dp[i]=-1;
        return c(n,dp);
    }
};