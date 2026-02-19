class Solution {
public:
    int countBinarySubstrings(string s) {

        
        int result=0;
        int n=s.length();
      for(int i=0;i<n;i++){
        long long count=0;
       char ch=s[i];
       int j=i;
       while(j<n && s[j]==ch ){
        count++;
        j++;
       }
       while(j<n && count!=0 && s[j]!=ch ){
        count--;
        j++;
       }
       if(count==0){
        result++;
       }
      }
    return result;
    }
};