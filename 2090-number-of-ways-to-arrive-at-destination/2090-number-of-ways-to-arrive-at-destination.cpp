class Solution {
public:
long long M= 1e9 +7;
    int countPaths(int n, vector<vector<int>>& roads) {

        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& road :roads){
            int u=road[0];
            int v=road[1];
            int time=road[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }

        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>> >pq;


        vector<long long> dist(n,LLONG_MAX);
        vector<long long> count(n,0);

        dist[0]=0;
        count[0]=1;
        pq.push({0,0});
        
        while(!pq.empty()){
            long long currtime=pq.top().first;
            int currNode= pq.top().second;

            pq.pop();
            if(currtime>dist[currNode]) continue;

            for(auto& neighbor:adj[currNode]){
                int nextNode = neighbor.first; 
                int time = neighbor.second;

                long long newtime=currtime+time;
                if(newtime <dist[nextNode]){
                    dist[nextNode]=newtime;
                    pq.push({newtime,nextNode});
                    count[nextNode]=count[currNode];
                }else if(newtime==dist[nextNode]){
                    count[nextNode]=(count[nextNode]+count[currNode])%M;

                }


            }
        }
        return count[n-1];
        
    }
};