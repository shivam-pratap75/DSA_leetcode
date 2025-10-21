class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Avoids overflow
            
            if (nums[mid] == target) {  // Fixed: compare nums[mid] with target
                return mid;
            }
            
            // Check which side is sorted
            if (nums[left] <= nums[mid]) {  // Left side is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // Target is in left sorted portion
                } else {
                    left = mid + 1;   // Target is in right portion
                }
            } else {  // Right side is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // Target is in right sorted portion
                } else {
                    right = mid - 1;  // Target is in left portion
                }
            }
        }
        
        return -1;
    }
};