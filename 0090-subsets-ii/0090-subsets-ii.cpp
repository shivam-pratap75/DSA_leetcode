class Solution {
public:

    void solve(vector<int>& nums,vector<vector<int>>& result,vector<int>& temp,int start){

        result.push_back(temp);


        for(int i=start;i<nums.size();i++){

            if(i>start && nums[i]==nums[i-1])continue;

                temp.push_back(nums[i]);

                solve(nums,result,temp,i+1);

                temp.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> result;

        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,result,temp,0);

        return result;

      
    }
};