class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;

   int nums=0;
    int result=0;
   while(true){
    nums=nums*10+1;
    result++;
    nums=nums%k;
    if(nums==0)return result;
   }
   return result;
        
    }
};