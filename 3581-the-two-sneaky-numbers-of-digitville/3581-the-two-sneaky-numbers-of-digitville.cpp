class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {


         vector<int> result;

        unordered_set<int> check;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(check.find(nums[i])!=check.end()){
                count++;
                result.push_back(nums[i]);
            }else{
                check.insert(nums[i]);
            }
            if(count==2){
                break;
            }
        }
        return result;
        
    }
};