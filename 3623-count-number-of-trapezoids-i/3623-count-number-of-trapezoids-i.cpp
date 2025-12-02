class Solution {
public:
    const int mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        long long ans =0;

        unordered_map<int,int> mp;
        for(auto i: points){
            mp[i[1]]++;
        }

        long long edgesSum =0;

        for(auto i: mp ){

            long long edges = (i.second*1LL*(i.second-1))/2;

            ans = (ans + edges*edgesSum)%mod;
            edgesSum+=edges;
        }

        return ans;
    }
};