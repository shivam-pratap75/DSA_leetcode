class Solution {
public:
    int minSwaps(vector<int>& nums) {
      
        int k=count(nums.begin(),nums.end(),1);
        int n=nums.size();
        int left=0,crr=0;
        if(k==n)return 0;
     vector<int> temp = nums;
     
         
         
        temp.insert(temp.end(), nums.begin(), nums.end());
        int result=0;
        for(int right=0;right<temp.size();right++){

            if(temp[right]==1)crr++;

            if(right-left+1>k){
                if(temp[left]==1)crr--;
                left++;
            }

           if(right - left + 1 == k){
                result = max(result, crr);
              }


        }

        return k-result;
     
    }
};