class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n=nums.size();
        pair<int,int>result;
        result={INT_MIN,0};
        unordered_map<int,int> temp;
        for(int i=0;i<n;i++){

            temp[nums[i]]++;
            if(result.second<temp[nums[i]]){
                result.second=temp[nums[i]];
                result.first=nums[i];
            }

        }
        return result.first;
    }
};