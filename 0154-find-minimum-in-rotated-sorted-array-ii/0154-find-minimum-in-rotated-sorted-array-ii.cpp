class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        int result=INT_MAX;

        while(left<=right){
            int mid=(left+right)/2;

            result=min(nums[mid],result);

            if(nums[mid]<nums[left] && nums[right]>nums[mid]){
                right=mid-1;
            }else if(nums[mid]>nums[left] && nums[right]<nums[mid]){
                left=mid+1;
            }else if(nums[mid]>nums[left] && nums[mid]<=nums[right]){
                right=mid-1;
            }else{
                left=mid+1;
            }


        }
        return result;
        
    }
};