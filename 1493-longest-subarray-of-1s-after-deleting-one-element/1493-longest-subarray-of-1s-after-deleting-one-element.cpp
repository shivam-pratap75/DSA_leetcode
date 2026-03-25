class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int check=0;
        int result=0;
        int left=0;

        for(int i=0;i<nums.size();i++){

            if(nums[i]==0)check++;

            if(check>1){
                while(check>1){
                    if(nums[left]==0)check--;
                    left++;
                }
            }
           result=max(result,i-left);
        }
        
    return result;
    }
};