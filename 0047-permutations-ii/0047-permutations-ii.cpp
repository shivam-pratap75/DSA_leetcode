class Solution {
public:

    void solve(vector<int>&nums, vector<vector<int>>& result,vector<int>&temp,vector<bool>& check){

        if(nums.size()==temp.size()){
            result.push_back(temp);
            return ;
        }

        for(int i= 0;i<nums.size();i++){

            if(i>0 && nums[i]==nums[i-1] && check[i-1])continue;

            if(check[i]){
                    int num=nums[i];
                    temp.push_back(num);
                    check[i]=false;

                    solve(nums,result,temp,check);

                    check[i]=true;
                    temp.pop_back();
            }


        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {

            vector<vector<int>> result;
            int n=nums.size();
            vector<bool>check(n,true);
            vector<int>temp;


           sort(nums.begin(),nums.end());
            
            solve(nums,result,temp,check);
            return result;
        
    }
};