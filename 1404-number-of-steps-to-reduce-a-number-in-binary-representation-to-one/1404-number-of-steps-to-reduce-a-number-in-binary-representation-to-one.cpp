class Solution {
public:
    int numSteps(string s) {
        int result = 0;
        int n = s.length();
        bool carry = false;
        int i = n - 1;

        while (i > 0) {
            if (s[i] == '1') {
                if (carry) {
                    result += 1;      
                } else {
                    result += 2;      
                    carry = true;
                }
            } else { 
                if (carry) {
                    result += 2;      
                } else {
                    result += 1;      
                }
            }
            i--;
        }

        if (carry) result++;          

        return result;
    }
};