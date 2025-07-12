class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        using ll = long long;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        vector<ll> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        int mod=1e9+7;
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            for (auto& [adjNode,wt]:adj[node]) {
                ll newDist=d+wt;
                if (newDist<dist[adjNode]) {
                    dist[adjNode]=newDist;
                    pq.push({newDist,adjNode});
                    ways[adjNode]=ways[node];
                } else if (newDist==dist[adjNode]) {
                    ways[adjNode]=(ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
