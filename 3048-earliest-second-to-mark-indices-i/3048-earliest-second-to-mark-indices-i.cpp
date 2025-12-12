class Solution {
public:
    bool helper(vector<int>& nums, vector<int>& changeIndices, int last) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for(int i=0; i<n; ++i) v.push_back({-1, -1});

        for(int i=0; i<=last; ++i) {
            int idx = changeIndices[i] - 1;
            v[idx] = {i+1, idx};
        }
        for(int i=0; i<n; ++i) {
            if(v[i].first == -1) return false;
        }
        

        sort(v.begin(), v.end());
        int sub = 0;
        for(int i=0; i<n; ++i) {
            int cut = nums[v[i].second];
            sub += cut + 1;
            if(v[i].first < sub) {
                return false;
            }
        }

        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int m = changeIndices.size();
        int l = 0, r = m-1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(helper(nums, changeIndices, mid)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        if(helper(nums, changeIndices, l)) return l+1;
        else return -1;

    }
};