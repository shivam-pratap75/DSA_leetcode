class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        map<int, vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                mp[grid[i][j]].push_back({i,j});

        vector<vector<vector<int>>> dist(n,
            vector<vector<int>>(m, vector<int>(k+1, INT_MAX)));

        using T = tuple<int,int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0][0] = 0;
        pq.push({0,0,0,0});

        // pointer per teleport layer
        vector<map<int, vector<pair<int,int>>>::iterator> ptr(k+1, mp.begin());

        while(!pq.empty()){
            auto [cost,i,j,t] = pq.top();
            pq.pop();

            if(cost > dist[i][j][t]) continue;
            if(i==n-1 && j==m-1) return cost;

            // normal moves
            if(i+1<n){
                int nc = cost + grid[i+1][j];
                if(nc < dist[i+1][j][t]){
                    dist[i+1][j][t] = nc;
                    pq.push({nc,i+1,j,t});
                }
            }
            if(j+1<m){
                int nc = cost + grid[i][j+1];
                if(nc < dist[i][j+1][t]){
                    dist[i][j+1][t] = nc;
                    pq.push({nc,i,j+1,t});
                }
            }

            // teleport
            if(t < k){
                int val = grid[i][j];

                while(ptr[t] != mp.end() && ptr[t]->first <= val){
                    for(auto &[x,y] : ptr[t]->second){
                        if(cost < dist[x][y][t+1]){
                            dist[x][y][t+1] = cost;
                            pq.push({cost,x,y,t+1});
                        }
                    }
                    ++ptr[t];
                }
            }
        }
        return -1;
    }
};
