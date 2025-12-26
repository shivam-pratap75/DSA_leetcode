// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         int n = grid[0].size();
//         if (n == 1) return 0;

        
//         vector<vector<long long>> gridLL(2, vector<long long>(n));
//         for(int i = 0; i < n; i++) {
//             gridLL[0][i] = grid[0][i];
//             gridLL[1][i] = grid[1][i];
//         }
        
        
//         for(int i = n-2; i >= 0; i--) {
//             gridLL[0][i] += gridLL[0][i+1];
//             gridLL[1][i] += gridLL[1][i+1];
//         }
        
        
//         long long minVal = LLONG_MAX;
//         int check = 0;
        
//         for(int i = 0; i < n; i++) {
//             long long temp1 = (i < n-1) ? gridLL[0][i+1] : 0;
//             long long temp2 = (i > 0) ? gridLL[1][0] - gridLL[1][i] : 0;
            
//             long long currentMax = max(temp1, temp2);
//             if (currentMax < minVal) {
//                 minVal = currentMax;
//                 check = i;
//             }
//         }
        
//         long long temp1 = (check < n-1) ? gridLL[0][check+1] : 0;
//         long long temp2 = (check > 0) ? gridLL[1][0] - gridLL[1][check] : 0;
       
//         return max(temp1, temp2);
//     }
// };


class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();  // Number of columns
        if (n == 1) return 0;

        // Don't modify the original grid - create separate arrays
        vector<long long> topSuffix(n + 1, 0);
        vector<long long> bottomSuffix(n + 1, 0);
        
        // Calculate suffix sums from right to left
        for(int i = n-1; i >= 0; i--) {
            topSuffix[i] = topSuffix[i+1] + grid[0][i];
            bottomSuffix[i] = bottomSuffix[i+1] + grid[1][i];
        }
        
        // Calculate prefix sums for bottom row
        vector<long long> bottomPrefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            bottomPrefix[i+1] = bottomPrefix[i] + grid[1][i];
        }
        
        // Find the optimal switching point
        long long result = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            // Top cells after i (from i+1 to end)
            long long temp1 = topSuffix[i+1];
            
            // Bottom cells before i (from 0 to i-1)
            long long temp2 = bottomPrefix[i];
            
            result = min(result, max(temp1, temp2));
        }
        
        return result;
    }
};