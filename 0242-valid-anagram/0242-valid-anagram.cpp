class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int>m1;
        for(int i=0;i<s.length();i++){
          m1[s[i]]++;
            
        }
        for(int i=0;i<s.length();i++){
          
          if(m1.find(t[i])!=m1.end()){
              m1[t[i]]--;
              if(m1[t[i]]==0){
                m1.erase(t[i]);
              }
          }else{
            return false;
          }
            
        }
        return true;
    }
};