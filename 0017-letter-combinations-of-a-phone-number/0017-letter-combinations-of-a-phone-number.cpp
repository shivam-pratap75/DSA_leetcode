class Solution {
public:

    void solve(vector<string>&temp,string& digits,vector<string>& result,string& help,int k){

        if(help.length()==digits.length()){
            result.push_back(help);
            return ;
        }

        int x=digits[k]-'0';
        for(int i=0;i<temp[x-2].length();i++){

            char ch=temp[x-2][i];

            help.push_back(ch);
            solve(temp,digits,result,help,k+1);

            help.pop_back();
        }

       
    }
    vector<string> letterCombinations(string digits) {

        vector<string> temp={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;

        string help="";
       
       solve(temp,digits,result,help,0);

       return result;
        
    }
};