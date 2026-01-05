class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        int mini_ele=INT_MAX;
        long long result=0;
        int count_negative=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp=abs(matrix[i][j]);
                result+=temp;
                mini_ele=min(mini_ele,temp);
                    if(matrix[i][j]<0) count_negative++;



            }
        }

        if( count_negative%2==0){
            return result;
        }else{
            return result-(2*mini_ele);
        }
        
    }
};