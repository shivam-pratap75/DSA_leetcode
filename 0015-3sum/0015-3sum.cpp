class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
   
  sort(nums.begin(),nums.end());
  vector<vector<int>> result;
  int k=0,left=0,right=nums.size()-1;


  for(int i=0;i<nums.size()-2;i++){
left=i+1;
right=nums.size()-1;
 if(i > 0 && nums[i] == nums[i-1]) continue;
    while(right>left){

        if(nums[i]+nums[left]+nums[right]>0){
            right--;
        }else if(nums[i]+nums[left]+nums[right]<0){
            left++;
        }else{
            result.push_back({nums[i], nums[left], nums[right]});
              while (left < right && nums[left] == nums[left + 1]) left++;
              while (left < right && nums[right] == nums[right - 1]) right--;

           left++;
           right--;
        }

    }
  }
  return result;

    }
        
    
};