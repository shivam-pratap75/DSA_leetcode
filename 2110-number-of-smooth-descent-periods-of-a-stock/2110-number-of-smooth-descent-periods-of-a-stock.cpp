class Solution {
public:
    
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        int prev = prices[0];
        long long cnt = 1;
        for(int i=1; i<n; i++){
            if(prices[i] == prev-1) cnt++;
            else{
                ans = ans + (cnt*(cnt+1)/2);
                cnt = 1;
            }
            prev = prices[i];
        }
        ans = ans + (cnt*(cnt+1)/2);
        return ans;
    }
};