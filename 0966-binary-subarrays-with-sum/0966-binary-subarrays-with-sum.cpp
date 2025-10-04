class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left=0,i=0;
        int n=nums.size();
        int result=0,curr=0;
        
      for(int i=0;i<n;i++) {
           if(nums[i]==1){
            curr++;
           }
           if(curr>goal){
            while(curr > goal && left < i) {
               if(nums[left] == 1) {
                     curr--;
                }
                    left++;
           }
           }
           
           if(curr==goal){
            result++;
            int temp=left;
            while(temp < i && nums[temp] == 0){
               
                result++;
                temp++;
            }
            
            
           }

       }

       return result;
        
    }
};