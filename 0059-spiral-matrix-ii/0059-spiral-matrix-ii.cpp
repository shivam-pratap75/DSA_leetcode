class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        int row1=0,row=n-1;
        int col1=0,col=n-1;
        int val=1;
    vector<vector<int>> result(n,vector<int>(n,0));
    while(row1<=row && col1<=col){

        for(int i=col1;i<=col;i++){
            result[row1][i]=val;
            val++;

        }
        row1++;
        for(int i=row1;i<=row;i++){
            result[i][col]=val;
            val++;
        }
        col--;
        for(int i=col;i>=col1;i--){
            result[row][i]=val;
            val++;
        }

        row--;
        for(int i=row;i>=row1;i--){
            result[i][col1]=val;
            val++;
        }
        col1++;
           
    }
    
    return result;      
        
    }
};