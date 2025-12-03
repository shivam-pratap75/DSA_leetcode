class Solution {
public:
    string lexSmallest(string s) {
        string res=s;
        int n=s.size();
        for(int k=1;k<=n;k++){
            string first=s;
            reverse(first.begin(),first.begin()+k);
            res=min(res,first);
            string last=s;
            reverse(last.end()-k,last.end());
            res=min(res,last);
        }
        return res;
    }
};