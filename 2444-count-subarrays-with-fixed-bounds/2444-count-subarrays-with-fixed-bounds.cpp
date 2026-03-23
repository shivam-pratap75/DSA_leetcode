class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

      
      
        int lastmin=-1;
        int lastmax=-1;
        long long result=0;
        int check=-1;
      for(int i=0;i<nums.size();i++){

        if(nums[i]<minK || nums[i]>maxK){
            check=i;
        }

        if(nums[i]==minK)lastmin=i;
        if(nums[i]==maxK)lastmax=i;


        int x=min(lastmin,lastmax);
        if(x>check){
            result+=x-check;
        }

        
      }
      return result;
    }
};