class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& nums,vector<int>& temp, vector<bool>& used) {

        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(!used[i]) {
                used[i] = true;
                temp.push_back(nums[i]);

                solve(nums,  temp, used);

                temp.pop_back();     
                used[i] = false;     
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> temp;
        vector<bool> used(nums.size(), false);

        solve(nums,  temp, used);
        return result;
    }
};