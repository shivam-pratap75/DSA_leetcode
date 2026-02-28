class Solution {
public:

  void solve(vector<vector<int>>& result,vector<int>& nums,vector<int>& temp,int i){

    if(i==nums.size()){
        result.push_back(temp);
        return ;
    }

    int num=nums[i];
    temp.push_back(num);
    solve(result,nums,temp,i+1);
    temp.pop_back();
    solve(result,nums,temp,i+1);


  }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int>temp;
        solve(result,nums,temp,0);
        return result;
        
    }
};