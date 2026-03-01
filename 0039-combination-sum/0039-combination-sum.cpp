class Solution {
public:

    void solve(vector<int>& candidates,vector<vector<int>>& result,int target,vector<int>& temp,int start){

        if(target<0)return;
        if(target==0){
            result.push_back(temp);
            return ;
        }

        for(int i=start;i<candidates.size();i++){

            int num=candidates[i];

            temp.push_back(num);
            solve(candidates,result,target-num,temp,i);

            

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
    solve(candidates,result,target,temp,0);


        return result;
    }
};