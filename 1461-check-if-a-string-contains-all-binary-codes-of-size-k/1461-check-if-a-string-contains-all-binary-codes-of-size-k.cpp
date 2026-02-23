class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int n=pow(2,k);
        unordered_set<string> temp;
        int i=0;
        while(i<s.length()){

                string temp1=s.substr(i,k);
                if(temp1.length()==k){
                temp.insert(temp1);

                }
                if(temp.size()==n)return true;

                i++;

        }
        
        return false;
    }
};