class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
int left=0;
int right=1;
while(right<nums.size()){
if(nums[left]==nums[right]){
    right++;
  
}else{
    left++;
      nums[left]=nums[right];
    right++;
}

}
return left+1;
        
    }
};