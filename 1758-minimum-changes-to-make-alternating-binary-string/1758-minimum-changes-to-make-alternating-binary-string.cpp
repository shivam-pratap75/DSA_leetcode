class Solution {
public:
    int minOperations(string s) {

        int odd=0,eve=0;

        for(int i=0;i<s.length();i++){
            if(i%2==0){
                if(s[i]=='0'){
                    odd++;
                }else{
                    eve++;
                }
            }else{
                 if(s[i]=='1'){
                    odd++;
                }else{
                    eve++;
                }
            }
        }
        return min(odd,eve);
    }
};