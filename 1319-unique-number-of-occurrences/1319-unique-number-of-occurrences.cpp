class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int,int>m;
       for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
       } 
       unordered_set<int>s;
        for(auto it:m){
            int k=s.size();
        s.insert(it.second);
        if(k==s.size()){
            return false;
        }
       } 
return true;
    }
};