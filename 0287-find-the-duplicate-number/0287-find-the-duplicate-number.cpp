class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> value;

        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(value.find(x)!=value.end()){
                return nums[i];
            }else{
                value.insert(x);
            }
        }
        return 1;

    }
};