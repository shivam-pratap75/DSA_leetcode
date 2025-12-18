class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
       

          int n=prices.size();
          vector<long long> pre(n),curr(n);

          
          pre[0]=prices[0];
          curr[0]=strategy[0]=strategy[0]* prices[0];

          
        for(int i=1; i<n; i++)
        {
            pre[i]=pre[i-1]+ prices[i];
            curr[i]=curr[i-1]+ (strategy[i] * prices[i]);

        }

        
        long long result=curr[n-1];

        for(int i=k-1; i<n; i++)
        {
            long long second_half_sum= pre[i]-pre[(i+(i-k+1))/2]+(i-k+1>0?curr[i-k]:0);
            long long difference=curr[i]-second_half_sum;
            result=max(result,curr[n-1]-difference);
        }

        return result;
        

            

      
     
    }
};