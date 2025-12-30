class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;
        
        if (rows < 3 || cols < 3) return 0;
        
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    result++;
                }
            }
        }
        
        return result;
    }
    
private:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        // Check if all numbers are from 1 to 9 and unique
        vector<bool> seen(10, false);
        
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || seen[num]) {
                    return false;
                }
                seen[num] = true;
            }
        }
        
        // Check all rows sum to 15
        for (int i = r; i < r + 3; i++) {
            if (grid[i][c] + grid[i][c+1] + grid[i][c+2] != 15) {
                return false;
            }
        }
        
        // Check all columns sum to 15
        for (int j = c; j < c + 3; j++) {
            if (grid[r][j] + grid[r+1][j] + grid[r+2][j] != 15) {
                return false;
            }
        }
        
        // Check diagonals
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != 15) {
            return false;
        }
        
        if (grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != 15) {
            return false;
        }
        
        return true;
    }
};