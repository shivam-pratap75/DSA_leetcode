class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

   int result=0;

   for(int i=0;i<nums.size();i++){
    int curr=0;
    int flag=0;
    for(int j=2;j<=nums[i]/2;j++){
        if(flag>2){
            break;
        }
        if(nums[i]%j==0){
           flag++;
           curr+=j;
        }
    }
    if(flag==2){
        result+=curr;
        result+=1+nums[i];
    }
   }



return result;
        
    }
};