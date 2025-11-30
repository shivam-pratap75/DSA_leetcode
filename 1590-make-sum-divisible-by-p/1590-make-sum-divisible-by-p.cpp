class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        
        // Calculate total sum
        for (int num : nums) {
            total += num;
        }
        
        // Find the remainder we need to remove
        int target_rem = total % p;
        if (target_rem == 0) return 0;
        
        // Use prefix sum and hash map to find the shortest subarray with sum % p == target_rem
        unordered_map<int, int> prefix_rem;
        prefix_rem[0] = -1; // Empty prefix has remainder 0 at index -1
        
        long long prefix_sum = 0;
        int result = n; // Initialize with maximum possible value
        
        for (int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            int current_rem = prefix_sum % p;
            
            // We're looking for: (current_rem - needed_rem) % p == 0
            // Which means: current_rem - needed_rem ≡ 0 (mod p)
            // So: current_rem ≡ needed_rem (mod p)
            int needed_rem = (current_rem - target_rem + p) % p;
            
            if (prefix_rem.find(needed_rem) != prefix_rem.end()) {
                result = min(result, i - prefix_rem[needed_rem]);
            }
            
            prefix_rem[current_rem] = i;
        }
        
        return result < n ? result : -1;
    }
};