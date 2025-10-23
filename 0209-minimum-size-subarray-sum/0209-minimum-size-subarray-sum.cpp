class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left=0;
        int result=INT_MAX;
        int sum=0;
        for(int right=0;right<nums.size();right++){
           sum+=nums[right];
            
            if(sum>=target){
                int a=right-left+1;
                result=min(result,a);
                  while(sum>=target){

                int b=right-left+1;
                result=min(result,b);
                 sum-=nums[left];
                left++;
            }
            }

           

        }
     if(result==INT_MAX){
        return 0;
     }
    return result;
        
    }
};