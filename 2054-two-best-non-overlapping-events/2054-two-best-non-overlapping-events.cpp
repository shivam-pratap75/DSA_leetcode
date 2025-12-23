class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<vector<int>>& events, int i, int count, vector<int>& starts) {
        int n = events.size();
        if (count == 2 || i >= n) return 0;
        
        if (dp[i][count] != -1) return dp[i][count];
        
        // not_take
        int not_take = solve(dp, events, i + 1, count, starts);
        
        // take
        int take = events[i][2];
        
        // Find next event that starts after current event ends
        // Use binary search since events are sorted
        int next_index = upper_bound(starts.begin(), starts.end(), events[i][1]) - starts.begin();
        //Finds the first event that starts after the current event ends
        //upper_bound returns iterator to first element > events[i][1]
        
        take += solve(dp, events, next_index, count + 1, starts);
        
        return dp[i][count] = max(not_take, take);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        
        
        vector<int> starts;
        for (auto& e : events) {
            starts.push_back(e[0]);
        }
        
        
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        
        return solve(dp, events, 0, 0, starts);
    }
};