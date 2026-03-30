class Solution {
public:
    bool checkStrings(string s1, string s2) {

        int n=s1.length();
       vector<int> temp1(26,0),temp2(26,0);

       for(int i=0;i<n;i++){
        if(i%2==0){
            temp1[s1[i]-'a']++;
            temp1[s2[i]-'a']--;
        }else{
            temp2[s1[i]-'a']++;
            temp2[s2[i]-'a']--;

        }
       }
        return temp1==vector<int>(26,0) && temp2==vector<int>(26,0);      
    }
};