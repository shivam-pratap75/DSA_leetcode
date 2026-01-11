class Solution {
public:
    int residuePrefixes(string s) {
        int answer = 0;
        unordered_set<char> st;  
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            st.insert(s[i]);  
            

            if (st.size() == ((i + 1) % 3)) {
                answer++;  
            }
        }
        return answer;
    }
};