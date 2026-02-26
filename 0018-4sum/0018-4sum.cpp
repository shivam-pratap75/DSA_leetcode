class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
         vector<vector<int>> result;
         sort(nums.begin(),nums.end());
        int n=nums.size();
         for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                    if(j>i+1 && nums[j]==nums[j-1])continue;
                    long long sum=nums[i]+nums[j];
                    int left=j+1,right=n-1;
                    while(left<right){
                        long long check=nums[left]+nums[right]+sum;

                        if(check==target){
                            vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[left]);
                            temp.push_back(nums[right]);
                            
                                result.push_back(temp);
                            while(left<right && nums[left]==nums[left+1])left++;
                            while(left<right && nums[right]==nums[right-1])right--;
                            
                            
                            left++;
                            right--;

                        }else if(check<target){
                            left++;
                        }else{
                            right--;
                        }
                    }
            }

         }
         return result;
    }
};