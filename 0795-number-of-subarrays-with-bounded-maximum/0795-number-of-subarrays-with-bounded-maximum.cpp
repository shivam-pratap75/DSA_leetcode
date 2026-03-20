class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {

        
        int result=0;
        int n=nums.size();
        int lastvalid=-1;
        int lastinvalid=-1;

        for(int i=0;i<n;i++){

            if(nums[i]>right)lastinvalid=i;

            if(nums[i]>=left)lastvalid=i;

            result += max(0, lastvalid - lastinvalid);
        }


    return result;


    }
};