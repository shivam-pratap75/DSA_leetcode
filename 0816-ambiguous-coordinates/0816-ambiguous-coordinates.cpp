class Solution {
public:
    vector<string> function(string s){
        int n = s.size();

        vector<string> result;

        if (n == 1 || s[0] != '0'){
            result.push_back(s);
        }

        for (int i = 1; i < n; i++){
            string a = s.substr(0,i);
            string b = s.substr(i);

            if (a[0] == '0' && a.size() > 1){
                break;
            }

            if (b[b.size()-1] == '0'){
                break;
            }

            string x = a + "." + b;
            
            result.push_back(x);
        }

        return result;
    }

    vector<string> ambiguousCoordinates(string s) {
        string t = s.substr(1);
        t.pop_back();

        int n = t.size();

        vector<string> ans;

        for (int i = 1; i < n; i++){
            vector<string> a = function(t.substr(0,i));
            vector<string> b = function(t.substr(i));
            for (auto i: a){
                for (auto j: b){
                    string x = "(" + i + ", " + j + ")";
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};