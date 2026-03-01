class Solution {
public:

    void solve(vector<vector<int>>& result,int k,int sum,vector<int> & temp,int start){

            if(sum<0)return;
        if(temp.size()==k && sum==0){
            result.push_back(temp);
            return;
        }

        for(int i=start;i<=9;i++){

           
            
            temp.push_back(i);

            solve(result,k,sum-i,temp,i+1);
            
            temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> result;
        vector<int> temp;

        solve(result,k,n,temp,1);
        return result;
    }
};