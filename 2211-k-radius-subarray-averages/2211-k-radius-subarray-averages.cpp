class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;
        vector<int> result(n, -1);
        
        // If window size is larger than array, return all -1
        if (windowSize > n) {
            return result;
        }
        
        long curr = 0;  // Use long to prevent overflow
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            curr += nums[right];
            
            // When we have a complete window of size (2*k + 1)
            if (right - left + 1 == windowSize) {
                int center = left + k;  // Center index
                result[center] = curr / windowSize;
                
                // Remove left element for next window
                curr -= nums[left];
                left++;
            }
        }
        
        return result;
    }
};