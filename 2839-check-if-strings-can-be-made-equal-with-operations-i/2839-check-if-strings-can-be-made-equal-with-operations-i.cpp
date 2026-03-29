class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        
        int n1=s1.length();
        int n2=s2.length();

        for(int i=0;i<n1-2;i++){
            if(s1[i]!=s2[i]){
                int x=i+2;
                if(s1[x]!=s2[i]){
                    return false;
                }else{
                    char temp =s1[i];
                    s1[i]=s1[x];
                    s1[x]=temp;

                }
            }
        }

        return s1==s2 ? true : false;
    }
};