class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLength = 0;
        map<char, int> m;
        int maxFreq = 0;  
        
        for (int right = 0; right < s.size(); right++) {
            m[s[right]]++;
            
            
            maxFreq = max(maxFreq, m[s[right]]);
            

            int windowLength = right - left + 1;
            

            while (windowLength - maxFreq > k) {
                m[s[left]]--;
                left++;
                windowLength = right - left + 1;
                
                maxFreq = 0;
                for (const auto& pair : m) {
                    maxFreq = max(maxFreq, pair.second);
                }
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};