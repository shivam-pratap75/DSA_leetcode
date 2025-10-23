class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> values;
        for (char c : s1) values[c]++;

        int left = 0;
        unordered_map<char, int> window_values;
        int matched_chars = 0; 

        for(int right = 0; right < s2.size(); right++) {
            char right_char = s2[right];
            
            
            if(values.find(right_char) != values.end()) {
                window_values[right_char]++;
                if(window_values[right_char] == values[right_char]) {
                    matched_chars++;
                }
            }

            
            if(right - left + 1 > s1.size()) {
                char left_char = s2[left];
                if(values.find(left_char) != values.end()) {
                    if(window_values[left_char] == values[left_char]) {
                        matched_chars--;
                    }
                    window_values[left_char]--;
                }
                left++;
            }

            
            if(matched_chars == values.size()) {
                return true;
            }
        }
        return false;
    }
};