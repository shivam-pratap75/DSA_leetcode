class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int count_one=0;
        int i=0;
        int result=0;
        while(i<n){
            while(i<n && s[i]=='1'){
                count_one++;
                i++;
            }
            if(i<n &&s[i]=='0'){
                result+=count_one;
                while(s[i]=='0'){
                    i++;
                }
            }

        }
        return result;
    }
};