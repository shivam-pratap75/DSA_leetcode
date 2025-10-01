class Solution {
public:
    void rotateFour(vector<vector<int>>& matrix, int i, int j, int n, int temp, int count) {
        if (count == 4) return; 
        
        
        int next_i = j;
        int next_j = n - 1 - i;
        int next_temp = matrix[next_i][next_j];
        

        matrix[next_i][next_j] = temp;
        
        
        rotateFour(matrix, next_i, next_j, n, next_temp, count + 1);
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                rotateFour(matrix, i, j, n, matrix[i][j], 0);
            }
        }
    }
};