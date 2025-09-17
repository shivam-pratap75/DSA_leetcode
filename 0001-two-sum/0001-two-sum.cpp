class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> num;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
          
            if(m.find(target-nums[i])!=m.end()){
                num.push_back(i);
            int a=m[target-nums[i]];
                num.push_back(a);
                return num;
            }else{
                  m[nums[i]]=i;
            }
        }
        return num;
    }
};