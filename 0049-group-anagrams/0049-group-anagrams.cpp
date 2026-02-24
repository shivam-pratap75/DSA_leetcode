class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n=strs.size();
        vector<vector<string>> result;
        unordered_map<string,vector<string>>temp;

        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end());

            temp[s].push_back(strs[i]);
        }

        for(auto s:temp){
            result.push_back(s.second);
        }
        return result;

     

    }
};