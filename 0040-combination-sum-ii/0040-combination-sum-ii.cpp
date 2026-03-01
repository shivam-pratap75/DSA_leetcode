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
            if(i>start && candidates[i]==candidates[i-1])continue;
            temp.push_back(num);
            solve(candidates,result,target-num,temp,i+1);

            temp.pop_back();
        }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        
        solve(candidates,result,target,temp,0);

        return result;

        
    }
};