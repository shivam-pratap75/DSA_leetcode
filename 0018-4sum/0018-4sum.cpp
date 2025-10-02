class Solution {
public:
    vector<vector<int >> fourSum(vector<int>& nums, int target) {

    sort(nums.begin(),nums.end());
    const int  n = nums.size();
    int left,right;
    vector<vector<int >> result;
   
   
    for(int i=0;i<n-3;i++){
    if(i>0 && nums[i]==nums[i-1] )continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1&& nums[j]==nums[j-1] ) continue;
            left=j+1;
            right=n-1;

            long long res=(long long)target-nums[i]-nums[j];
            while(left<right){
                long long sum=(long long)nums[left]+nums[right];
             if(sum==res){
                 result.push_back({nums[i],nums[j],nums[left],nums[right]});
                while(left<right && nums[left]==nums[left+1])left++;
              while(left<right && nums[right]==nums[right-1])right--;
               right--;
                left++;
             }else if(sum<res){ 
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