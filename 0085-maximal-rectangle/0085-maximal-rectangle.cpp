class Solution {
public:

    int solve(vector<int>&height){
        stack<int> temp;
        int n=height.size();
        int area=0;

        height.push_back(0);
        for(int i=0;i<=n;i++){

            while(!temp.empty() && height[temp.top()]>height[i]){
                int h=height[temp.top()];
                temp.pop();
                int width;
                if(!temp.empty()){
                    width=i-temp.top()-1;
                }else{
                    width=i;
                }

                area=max(area,h*width);
            }
            temp.push(i);


        }
        height.pop_back();
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        int result=0;
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }

               
            }
             result=max(result,solve(height));
        }
        return result;
    }
};