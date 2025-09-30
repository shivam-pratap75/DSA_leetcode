class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int result = 0;
        map<int, int> numMap;
        int left = 0, right = 0;
        int n = nums.size();
        int countWithK = 0;
        
        while (right < n) {
            numMap[nums[right]]++;
            
            while (numMap.size() > k) {
                numMap[nums[left]]--;
                if (numMap[nums[left]] == 0) {
                    numMap.erase(nums[left]);
                }
                left++;
                countWithK = 0;  
            }
            
            
            while (numMap[nums[left]] > 1) {
                numMap[nums[left]]--;
                left++;
                countWithK++;
            }
            
            if (numMap.size() == k) {
                result += (1 + countWithK);
            }
            
            right++;
        }
        
        return result;
    }
};