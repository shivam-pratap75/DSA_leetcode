class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.empty()) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target == nums[mid]) {
               
                int start = mid;
                while (start > 0 && nums[start - 1] == target) {
                    start--;
                }
                
               
                int end = mid;
                while (end < nums.size() - 1 && nums[end + 1] == target) {
                    end++;
                }
                
                result.push_back(start);
                result.push_back(end);
                break;
            }
            else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (result.size() == 0) {
            result.push_back(-1);
            result.push_back(-1);
        }

        return result;
    }
};