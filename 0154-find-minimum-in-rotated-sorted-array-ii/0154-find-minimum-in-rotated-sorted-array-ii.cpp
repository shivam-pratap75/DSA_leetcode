class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left=0,right=nums.size()-1;
        int result=INT_MAX;
        while(left<=right){
            int mid=(left+right)/2;
        if(nums[mid]<result){
            result=nums[mid];
        }

        if(nums[left]==nums[right]){
            left++;
            continue;
        }
        
        if(nums[mid]>=nums[left]){
          int a=nums[left];
          result=min(result,a);
          left=mid+1;

        }else{

           int a=nums[mid];
           result=min(result,a);
           right=mid-1;

        }
            
        }


    return result;
        
    }
};