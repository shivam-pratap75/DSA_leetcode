class Solution {
public:
    int maxVowels(string s, int k) {
        int result=0;
        int left=0;
        int count=0;
        for(int i=0;i<s.length();i++){

        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
                    count++;
                }

                if(i-left+1>k){
                    while(i-left+1>k){
               if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' ||      s[left] =='u' ){
                    count--;
                }      left++; 

                    }
                }


                result=max(result,count);

        }
        return result;
    }
};