class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<pair<int,int>>> temp(n,vector<pair<int,int>>(m,{0,0}));
        int check=false;
        char ch=grid[0][0];

        int result=0;

        for(int i=0;i<n;i++){
            int c_x=0,c_y=0;
            for(int j=0;j<m;j++){
               
                if(grid[i][j]=='X'){
                    check=true;
                    c_x++;
                }else if(grid[i][j]=='Y'){
                    c_y++;
                }
                pair<int ,int> num;
                if(i>0){
                    int a=temp[i-1][j].first +c_x;
                    int b=temp[i-1][j].second + c_y;
                    temp[i][j]={a,b};

                    if(a == b && a > 0)result++;

                }else{
                    temp[i][j]={c_x,c_y};
                   if(c_x == c_y && c_x > 0) result++;
                }


            }
        }
        return result;
    }
};