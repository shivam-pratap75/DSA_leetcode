class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numSub(string s) {
        int n = s.size();
        long long result = 0;
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                count++;
                result = (result + count) % MOD;
            } else {
                count = 0;
            }
        }
        
        return result;
    }
};