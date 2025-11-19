class Solution {
public:

void solve(int n,int open,vector<string>&result,string s){
    if(n==0&& open==0){
        result.push_back(s);
        return;
    }

    if(n>0){
        solve(n-1,open+1,result,s+'(');
    }
    if(open>0){
        solve(n,open-1,result,s+')');
    }


}
    vector<string> generateParenthesis(int n) {

        vector<string> result;

        solve(n,0,result,"");
        return result;
        
    }
};