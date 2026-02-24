class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n+1,0);
        vector<int>result;

        for(int i=0;i<n;i++){
            int a=nums[i];
            if(temp[a]!=0)result.push_back(a);
            temp[a]+=1;
        }

    return result;
    
        
    }
};