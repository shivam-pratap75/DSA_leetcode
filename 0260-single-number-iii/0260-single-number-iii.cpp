class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==2)return nums;
        

        long long temp=0;

        for(int i=0;i<n;i++){
            temp^=nums[i];
        }

        // mask -> this will give rightmost set bit 

        int mask=(temp) & (-temp);
        int num1=0,num2=0;
        for(int num : nums){
            if(num & mask){
                num1^=num;
            }else{
                num2^=num;
            }
        }
        
        return {num1,num2};
    }
};