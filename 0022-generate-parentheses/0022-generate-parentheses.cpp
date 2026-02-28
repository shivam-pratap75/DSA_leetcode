class Solution {
public:

    void solve(int & n, vector<string>& result, string& temp,int op,int cl){
        if(temp.length()==n*2 && op==n && cl==n){
            result.push_back(temp);
            return;
        }
        
            if(op<n){
                temp+='(';
                solve(n,result,temp,op+1,cl);
                temp.pop_back();
            }
            if(cl<op){
                temp+=')';
                solve(n,result,temp,op,cl+1);
                temp.pop_back();
            }
        
    }
    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string temp="";
        solve(n,result,temp,0,0);
        return result;

        
    }
};