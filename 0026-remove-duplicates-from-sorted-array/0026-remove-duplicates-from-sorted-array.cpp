class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
int left=0;
int right=1;
int k;
while(right<nums.size()){
if(nums[left]==nums[right]){
    nums.erase(nums.begin() + left);
}else{
    left++;
    right++;
}

}

    
k=nums.size();
return k;
        
    }
};