class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0; 
        
        int left = 0;
        int result = 0;
        int curr_product = 1;
        
        for (int right = 0; right < nums.size(); right++) {
            curr_product *= nums[right];
            
            
            while (curr_product >= k && left <= right) {
                curr_product /= nums[left];
                left++;
            }
            
           
            result += (right - left + 1);
        }
        
        return result;
    }
};