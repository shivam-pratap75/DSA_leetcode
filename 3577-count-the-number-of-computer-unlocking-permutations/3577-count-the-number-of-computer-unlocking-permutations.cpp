class Solution {
public:
    const int MOD=1e9+7;
    int countPermutations(vector<int>& complexity) {
        long ans=1;
        int n=complexity.size();
        for(int i=1;i<n;i++)
        {
            if(complexity[i]<=complexity[0])
            {
                return 0;
            }
        }

        for(int i=1;i<n;i++)
        {
            ans=(ans*i)%MOD;
        }
        return ans;
    }
};