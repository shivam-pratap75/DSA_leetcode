class Solution {
public:
    void sortColors(vector<int>& nums) {

   int n=nums.size();
   int left=0,right=n-1;
   
   for(int i=0;i<=right;i++){
   if(nums[i]==0){
    int temp=nums[i];
    nums[i]=nums[left];
    nums[left]=temp;
    left++;
   }else if(nums[i]==2){

   
     int temp=nums[i];
    nums[i]=nums[right];
    nums[right]=temp;
    right--;
    i--;

   }
 


   }



        
    }
};