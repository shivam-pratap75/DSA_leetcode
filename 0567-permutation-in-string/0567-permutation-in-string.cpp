class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        unordered_map<char, int> values;
        for (char c : s1) values[c]++;
       
      
        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            if (values.count(s2[i])) {
                unordered_map<char, int> temp = values;
                int usedChars = 0;
                
                for (int j = i; j < s2.size() && usedChars < s1.size(); j++) {
                    char c = s2[j];
                    if (!temp.count(c) || temp[c] == 0) break;
                    
                    temp[c]--;
                    usedChars++;
                    
                    if (usedChars == s1.size()) {
                        bool allUsed = true;
                        for (auto& [ch, cnt] : temp) {
                            if (cnt != 0) {
                                allUsed = false;
                                break;
                            }
                        }
                        if (allUsed) return true;
                    }
                }
            }
        }
        return false;
    }
};