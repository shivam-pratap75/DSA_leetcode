class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int k=grid[0].size();
        int result=0;
        for(int i=n-1;i>=0;i--){
            for(int j=k-1;j>=0;j--){
                if(grid[i][j]<0){
                    result++;
                }else{
                    break;
                }
            }
        }
        return result;
    }
};