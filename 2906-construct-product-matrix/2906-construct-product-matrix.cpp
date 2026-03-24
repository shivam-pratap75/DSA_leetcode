class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int mod = 12345;

        vector<int> flat;

        // Flatten matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                flat.push_back(grid[i][j] % mod);
            }
        }

        int sz = flat.size();
        vector<int> prefix(sz, 1), suffix(sz, 1);

        // Prefix
        for(int i = 1; i < sz; i++){
            prefix[i] = (prefix[i-1] * flat[i-1]) % mod;
        }

        // Suffix
        for(int i = sz - 2; i >= 0; i--){
            suffix[i] = (suffix[i+1] * flat[i+1]) % mod;
        }

        vector<vector<int>> result(n, vector<int>(m));

        int idx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = (prefix[idx] * suffix[idx]) % mod;
                idx++;
            }
        }

        return result;
    }
};