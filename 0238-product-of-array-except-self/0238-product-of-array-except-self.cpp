class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
    vector<int>temp(n,0);
        int result=1;
        int c_zero=0;
        int idx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                c_zero++;
                idx=i;
                continue;
            }
            result*=nums[i];
            
        }

        if(c_zero>=2)return temp;
        if(c_zero==1){
            temp[idx]=result;
            return temp;
        }
        for(int i=0;i<nums.size();i++){
          int  val=result/nums[i];
            temp[i]=val;
           
        }
        return temp;
        
    }
};