class Solution {
public:
    int countBinarySubstrings(string s) {

        
        int result=0;
        int n=s.length();
         char ch=s[0];
         int count=0;
      for(int i=0;i<n;i++){
        
        if(ch==s[i]){
            count++;
            continue;
        }
      
       int j=i;
      int count2=0;
       while(j<n && count2<=count && s[j]!=ch ){
        count2++;
        j++;
       }

       int ans=min(count,count2);
       result+=ans;
       ch=s[i];
       count=1;
    
      }
    return result;
    }
};