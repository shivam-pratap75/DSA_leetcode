#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        
        if (s[0] == '-') {
            std::reverse(s.begin() + 1, s.end());
        } else {
            std::reverse(s.begin(), s.end());
        }
        
    
        long long y = stoll(s);
        

        if (y > INT_MAX || y < INT_MIN) {
            return 0;
        }
        
        return (int)y;
    }
};