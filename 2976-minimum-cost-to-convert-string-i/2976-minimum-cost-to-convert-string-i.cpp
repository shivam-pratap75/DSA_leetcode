class Solution {
public:
    const long long INF = LLONG_MAX;

    vector<long long> dijkstra(char src, unordered_map<char,vector<pair<char,int>>> &grp) {

        vector<long long> dist(26, INF);

        priority_queue<pair<long long,char>,
                       vector<pair<long long,char>>,
                       greater<>> pq;

        dist[src - 'a'] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto [dis, node] = pq.top();
            pq.pop();

            int idx = node - 'a';
            if(dis > dist[idx]) continue;

            for(auto &[next, w] : grp[node]){
                int nextIdx = next - 'a';
                if(dist[nextIdx] > dis + w){
                    dist[nextIdx] = dis + w;
                    pq.push({dist[nextIdx], next});
                }
            }
        }
        return dist;
    }

    long long minimumCost(string source, string target,
                          vector<char>& original, vector<char>& changed, vector<int>& cost) {

        unordered_map<char,vector<pair<char,int>>> grp;

        for(int i = 0; i < original.size(); i++){
            grp[original[i]].push_back({changed[i], cost[i]});
        }

        vector<vector<long long>> cache(26);
        vector<bool> computed(26, false);

        long long result = 0;

        for(int i = 0; i < source.size(); i++){
            if(source[i] == target[i]) continue;

            int u = source[i] - 'a';
            int v = target[i] - 'a';

            // Run Dijkstra only once per letter
            if(!computed[u]){
                cache[u] = dijkstra(source[i], grp);
                computed[u] = true;
            }

            long long d = cache[u][v];
            if(d == INF) return -1;

            result += d;
        }

        return result;
    }
};
