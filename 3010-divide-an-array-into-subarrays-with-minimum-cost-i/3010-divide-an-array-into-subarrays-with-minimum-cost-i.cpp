class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int temp=nums[0];

        sort(nums.begin(),nums.end());
        int result=0;
        bool check=false;
        for(int i=0;i<=2;i++){
            if(temp!=nums[i]){
                result+=nums[i];
            }else{
                check=true;
                result+=nums[i];
            }
        }
        if(check){
            return result;
        }else{
            result-=nums[2];
            result+=temp;
            return result;
        }

        
    }
};