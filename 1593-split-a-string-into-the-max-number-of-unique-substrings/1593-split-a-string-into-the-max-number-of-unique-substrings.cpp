class Solution {
public:

    void solve(string& s,int start,int& result,unordered_set<string>& temp){


        if(start==s.length()){
            int n=temp.size();
            result=max(result,n);
            return ;
        }

        for(int i=start;i<s.length();i++){

                    
            string sub_str=s.substr(start,i-start+1);

            if(temp.count(sub_str))continue;
            temp.insert(sub_str);

            solve(s,i+1,result,temp);
            temp.erase(sub_str);

            
        }
    }
    int maxUniqueSplit(string s) {

        
        int result=0;
        int n=s.length();
        unordered_set<string> temp;
        solve(s,0,result,temp);
        return result;
        
    }
};