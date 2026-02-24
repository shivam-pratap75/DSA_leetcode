class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int result = INT_MAX;

        while (left <= right) {
            int mid = (left + right) / 2;

            result = min(result, nums[mid]);

            
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }

            else if (nums[mid] <= nums[right]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return result;
    }
};