class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        // if(n<=3)return false;
        int temp=nums[0];
        int change=1;
        for(int i=1;i<n;i++){
            if(change>=4)return false;
            if (nums[i] == temp) return false;
            if(change ==1 && temp>=nums[i]){
                if(i==1)return false;
                change++;
            }else if(change==2 && temp<=nums[i]){
                if(temp>=nums[i-2])return false;
                change++;
            }else if(change==3 && temp>=nums[i]){
                change++;
            }

            temp=nums[i];

        }

    if(change!=3) return false;


        return true;
        
    }
};