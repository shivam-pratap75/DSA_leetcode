// class Solution {
// public:

// void bfs2(vector<vector<int>>& grid,pair<int,int>& pp,vector<vector<pair<int,int>>>& temp){

//     vector<pair<int,int>>res;

//      int n=grid.size();
//     int m=grid[0].size();

//     int i=pp.first;
//     int j=pp.second;

//     if(i-1>=0 && grid[i-1][j]==1 ){
//         grid[i-1][j]=2;

//         pair<int,int>p1;
//         p1.first=i-1;
//         p1.second=j;
//         res.push_back(p1);

        
//     }

//     if(i+1<n && grid[i+1][j]==1 ){
//         grid[i+1][j]=2;
//         pair<int,int>p1;
//         p1.first=i+1;
//         p1.second=j;
//         res.push_back(p1);
//     }

//     if(j-1>=0 && grid[i][j-1]==1 ){
//         grid[i][j-1]=2;
//         pair<int,int>p1;
//         p1.first=i;
//         p1.second=j-1;
//         res.push_back(p1);
//     }

//     if(j+1<m && grid[i][j+1]==1 ){
//         grid[i][j+1]=2;
//         pair<int,int>p1;
//         p1.first=i;
//         p1.second=j+1;
//         res.push_back(p1);
//     }

//     if(!res.empty()){
//         temp.push_back(res);
//     }
    

// return ;
// }
// void bfs(vector<vector<pair<int,int>>>& temp,int k,vector<vector<int>>& grid){

//     for(int i=0;i<temp[k].size();i++){

//         pair<int,int> pp;
//         pp=temp[k][i];

//         bfs2(grid,pp,temp);
//     }

    
//     return;

// }
//     int orangesRotting(vector<vector<int>>& grid) {

//         int n=grid.size();
//         int m=grid[0].size();
//         int result=0;

//         vector<vector<pair<int,int>>>temp;
       
//        for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){

//             if(grid[i][j]==2){
//                 pair<int,int> p;
//                 p.first=i;
//                 p.second=j;
//                 vector<pair<int,int>> v;
//                 v.push_back(p);
//                 temp.push_back(v);
//             }
            
//         }
//        }

//        int k=0;

//     while(k < temp.size()){

//     int prevSize = temp.size();

//      bfs(temp,k,grid);

//     if(temp.size() > prevSize){
//         result++;
//     }

//     k++;
// }

//     for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         if(grid[i][j]==1)
//             return -1;
//     }
// }


//       return result;  
        
//     }
// };





// ------------------------With using queue instead of vector -----------------//

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 2)
                    q.push({i,j});

                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int result = 0;

        while(!q.empty()){

            int size = q.size();
            bool changed = false;

            for(int i=0;i<size;i++){

                auto pp = q.front();
                q.pop();

                int x = pp.first;
                int y = pp.second;

                if(x-1>=0 && grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                    fresh--;
                    changed = true;
                }

                if(x+1<n && grid[x+1][y]==1){
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                    fresh--;
                    changed = true;
                }

                if(y-1>=0 && grid[x][y-1]==1){
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                    fresh--;
                    changed = true;
                }

                if(y+1<m && grid[x][y+1]==1){
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                    fresh--;
                    changed = true;
                }
            }

            if(changed) result++;
        }

        if(fresh>0) return -1;

        return result;
    }
};