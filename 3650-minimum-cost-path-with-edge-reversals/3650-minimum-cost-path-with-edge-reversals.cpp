class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> temp(n);

        for(auto &ed : edges){
            int u = ed[0];
            int v = ed[1];
            int wt = ed[2];
            temp[u].emplace_back(v, wt);
            temp[v].emplace_back(u, wt * 2);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> result(n, INT_MAX);
        result[0] = 0;

        pq.emplace(0, 0); 

        while(!pq.empty()){
            auto [dist, node] = pq.top();  
            pq.pop();

            if(dist > result[node]) continue;  

            if(node == n-1) return dist;

            for(auto &te : temp[node]){
                int adjnode = te.first;
                int adjdist = te.second;

                if(dist + adjdist < result[adjnode]){
                    result[adjnode] = dist + adjdist;
                    pq.emplace(result[adjnode], adjnode);
                }
            }
        }
        return -1;
    }
};
