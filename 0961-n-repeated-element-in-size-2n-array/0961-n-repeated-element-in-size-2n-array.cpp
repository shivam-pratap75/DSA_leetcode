class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> temp;
        int n=nums.size();
        int k=n/2;
        for(int i=0;i<n;i++){
                temp[nums[i]]++;
                if(temp[nums[i]]>1){
                    return nums[i];
                }
        }
        return 0;
        
    }
};