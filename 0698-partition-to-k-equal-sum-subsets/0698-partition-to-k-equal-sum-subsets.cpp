class Solution {
public:

    bool solve(vector<bool>& used, vector<int>& nums,
               int k, int start, int target, int curr_sum) {

        if (k == 0) return true;

        if (curr_sum == target)
            return solve(used, nums, k - 1, 0, target, 0);

        for (int i = start; i < nums.size(); i++) {

            if (used[i]) continue;

            
            if (i > start && nums[i] == nums[i-1] && !used[i-1]) continue;

            int num = nums[i];
            if (curr_sum + num > target) continue;

            used[i] = true;

            if (solve(used, nums, k, i + 1, target, curr_sum + num))
                return true;

            used[i] = false;

            
            if (curr_sum == 0) break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % k != 0) return false;

        int target = total_sum / k;
        vector<bool> used(nums.size(), false);

        
        sort(nums.rbegin(), nums.rend());

        return solve(used, nums, k, 0, target, 0);
    }
};