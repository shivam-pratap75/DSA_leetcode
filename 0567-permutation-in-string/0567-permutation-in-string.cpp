class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> values;
        for (char c : s1) {
            values[c]++;
        }
       
        for (int i = 0; i < s2.size(); i++) {
            if (values.find(s2[i]) != values.end()) {
                unordered_map<char, int> temp = values;
                int j = i;
                
                while (j < s2.size()) {
                    if (temp.find(s2[j]) != temp.end() && temp[s2[j]] > 0) {
                        temp[s2[j]]--;
                        if (temp[s2[j]] == 0) {
                            temp.erase(s2[j]);
                        }
                        j++;
                        if (temp.empty()) return true;
                    } else {
                        break;
                    }
                }
              
            }
        }
        return false;
    }
};