class Solution {
public:
    int minLengthAfterRemovals(string s) {

        
        int countA = 0, countB =0;
        
        
        for (char c : s) {
            if (c == 'a') {
                countA++;
            } else {
                countB++;
            }
        }
        
        
        return abs(countA - countB);
        
    }
};