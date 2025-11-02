class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
       vector<vector<int>> matrix(m, vector<int>(n, 0));
       int result = 0;
       
       
       for(int i = 0; i < walls.size(); i++) {
          int a = walls[i][0];
          int b = walls[i][1];
          matrix[a][b] = -1;
       }

       
       for(int i = 0; i < guards.size(); i++) {
          int a = guards[i][0];
          int b = guards[i][1];
          matrix[a][b] = 2;
       }

       
       for(int i = 0; i < guards.size(); i++) {
        int a = guards[i][0];
        int b = guards[i][1];

        
        int k = a + 1;
        int j = b;
        while(k < m && matrix[k][j] != -1 && matrix[k][j] != 2) {
            if(matrix[k][j] == 0) {  
                result++;
                matrix[k][j] = 1;
            }
            k++;
        }

         
        k = a - 1;
        j = b;
        while(k >= 0 && matrix[k][j] != -1 && matrix[k][j] != 2) {
            if(matrix[k][j] == 0) {  
                result++;
                matrix[k][j] = 1;
            }
            k--;
        }

        
        k = a;
        j = b + 1;
        while(j < n && matrix[k][j] != -1 && matrix[k][j] != 2) {
            if(matrix[k][j] == 0) {  
                result++;
                matrix[k][j] = 1;
            }
            j++;
        }

        
        k = a;
        j = b - 1;
        while(j >= 0 && matrix[k][j] != -1 && matrix[k][j] != 2) {
            if(matrix[k][j] == 0) {  
                result++;
                matrix[k][j] = 1;
            }
            j--;
        }
       }

       return n*m - (walls.size() + guards.size() + result);
    }
};