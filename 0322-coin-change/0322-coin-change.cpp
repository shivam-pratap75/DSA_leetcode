class Solution {
public:

    int solve(vector<int>& coins,int amount,vector<int>&temp){

        if(amount==0) return 0;
        if(amount<0) return INT_MAX;

        if(temp[amount]!=-1)return temp[amount];

        int ans=INT_MAX;

        for(int coin : coins){

            int result=solve(coins,amount-coin,temp);

            if(result!=INT_MAX){
                ans=min(ans,result+1);
            }
        } 

    return temp[amount]=ans;

    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int> temp(amount+1,-1);

    int ans= solve(coins,amount,temp);

    return ans!=INT_MAX ? ans :-1;
    

        
        
    }
};