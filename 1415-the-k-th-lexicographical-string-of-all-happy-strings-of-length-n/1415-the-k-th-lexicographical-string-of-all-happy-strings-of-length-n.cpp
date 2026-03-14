class Solution {
public:
    void solve(int n,int& k,int j,string& s,string temp,string& result){
        if(k==0)return;
        if(temp.size()==n){
            k--;
            if(k==0){
                result=temp;
            }
            return ;
        }


        for(int i=0;i<3;i++){

           if(!temp.empty() && temp.back()==s[i])continue;
            temp+=s[i];
            solve(n,k,i,s,temp,result);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {

        string s="abc";
        string result="";

        solve(n,k,0,s,"",result);
        return result;

        
    }
};