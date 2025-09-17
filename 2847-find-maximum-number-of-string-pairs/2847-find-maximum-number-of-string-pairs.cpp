class Solution {
public:
    string reverse(string a){
        string s="";
        
          for(int i=a.length()-1;i>=0;i--){
            s+=a[i];
               
          }
          return s;
    }
    int maximumNumberOfStringPairs(vector<string>& words) {
          unordered_set<string> s;
        int count =0;
        string r="";
        int k;
        for(int i=0;i<words.size();i++){
            s.insert(words[i]);            
        }
          for(int i=0;i<words.size();i++){
            k=s.size();
            r = reverse(words[i]);
            if(r==words[i]){
                continue;
            }
              s.insert(r);
              
              if(k==s.size()){
                count++;
              }  

        }

        return count/2;
    }
};