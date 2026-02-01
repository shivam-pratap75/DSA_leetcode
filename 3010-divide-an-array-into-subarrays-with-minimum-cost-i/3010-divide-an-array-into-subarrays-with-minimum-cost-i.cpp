class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int temp=nums[0];

        sort(nums.begin()+1,nums.end());
       return temp+nums[1]+nums[2];
        
    }
};