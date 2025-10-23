class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int result = INT_MIN;
        int curr = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            
            // When window reaches size k, start sliding
            if(i >= k - 1) {
                result = max(result, curr);
                curr -= nums[left];  // Remove leftmost element for next iteration
                left++;              // Move left pointer
            }
        }
        
        return static_cast<double>(result) / k;
    }
};