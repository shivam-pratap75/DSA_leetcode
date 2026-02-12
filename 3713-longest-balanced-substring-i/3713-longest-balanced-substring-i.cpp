class Solution {
public:
    int longestBalanced(string s) {
        
        int result = 0;
        int n = s.length();

        for(int i = 0; i < n; i++) {
            
            unordered_map<char,int> temp;
            unordered_set<char> temp1;

            for(int j = i; j < n; j++) {

                temp[s[j]]++;
                temp1.insert(s[j]);

                int num = temp[s[j]];
                bool flag = true;

                for(auto &x : temp) {
                    if(x.second != num) {
                        flag = false;
                        break;
                    }
                }

                if(flag) {
                    int idx = (j - i + 1);
                    result = max(result, idx);
                }
            }
        }

        return result;
    }
};
