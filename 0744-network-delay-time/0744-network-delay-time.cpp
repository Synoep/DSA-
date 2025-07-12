class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1); 
        for (auto& time:times) {
            int u = time[0],v=time[1],w=time[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            for (auto& [neighbor,weight]:adj[node]) {
                if (time + weight < dist[neighbor]) {
                    dist[neighbor]=time+weight;
                    pq.push({dist[neighbor],neighbor});
                }
            }
        }

        int maxi=0;
        for (int i=1;i<=n;i++) {
            if (dist[i]==INT_MAX) return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
    }
};