class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1) return 0;

        
        vector<vector<long long>> gridLL(2, vector<long long>(n));
        for(int i = 0; i < n; i++) {
            gridLL[0][i] = grid[0][i];
            gridLL[1][i] = grid[1][i];
        }
        
        
        for(int i = n-2; i >= 0; i--) {
            gridLL[0][i] += gridLL[0][i+1];
            gridLL[1][i] += gridLL[1][i+1];
        }
        
        
        long long minVal = LLONG_MAX;
        int check = 0;
        
        for(int i = 0; i < n; i++) {
            long long temp1 = (i < n-1) ? gridLL[0][i+1] : 0;
            long long temp2 = (i > 0) ? gridLL[1][0] - gridLL[1][i] : 0;
            
            long long currentMax = max(temp1, temp2);
            if (currentMax < minVal) {
                minVal = currentMax;
                check = i;
            }
        }
        
        long long temp1 = (check < n-1) ? gridLL[0][check+1] : 0;
        long long temp2 = (check > 0) ? gridLL[1][0] - gridLL[1][check] : 0;
       
        return max(temp1, temp2);
    }
};