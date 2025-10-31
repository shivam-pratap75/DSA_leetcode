class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> check;

        for(int i=0;i<nums.size();i++){
            
            if(check.find(nums[i])!=check.end()){
                result.push_back(nums[i]);
            }else{
                check.insert(nums[i]);
            }
        }
        return result;
        
    }
};