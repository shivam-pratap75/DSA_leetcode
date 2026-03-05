class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int result = 0;

        for (int i = 1; i < word.length(); i++) {
            if (abs(word[i] - word[i-1]) <= 1) {
                result++;
                i++;   
            }
        }

        return result;
    }
};