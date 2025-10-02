class Solution {
public:
    int triangularSum(vector<int>& nums) {

const int n=nums.size();
int left,right,size=n;
   for(int i=0;i<n-1;i++){
left=0;
while(left<size-1){
int sum=nums[left]+nums[right];
   nums[left] = (nums[left] + nums[left + 1]) % 10;
left++;

}
size--;

   }


   return nums[0];     
    }
};