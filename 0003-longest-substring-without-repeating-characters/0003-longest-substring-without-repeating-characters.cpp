class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num=0;
        string s1="";
       
        int x;
        int len = s.length();
        if(len==1){
            return 1;
        }

            for(int i=0;i<len;i++){
              
               if(s1.find(s[i]) != string::npos){
                 
               s1.erase(0,s1.find(s[i])+1);
               }
               s1+=s[i];
                x = s1.length();
                 num =max(x,num);
               
            }
            if(num==0){
                num=s.length();
            }
    return num;    
    }   
};