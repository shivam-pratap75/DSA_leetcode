class Solution {
public:
    int minimumDeletions(string s) {

        int b=0, result=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                b++;
            }else{
                result=min(result+1,b);

            }
        }
        return result;
      
    }
};