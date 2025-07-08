class Solution {
public:
    void dfs(int node, vector<int> &vis,vector<vector<int>>&adj) {
        vis[node]=1;
        for (auto a:adj[node]) {
            if (!vis[a]) {
                dfs(a,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(edges[i][j]==1) adj[i].push_back(j);
            }
        }
        vector<int> vis(n, 0);
        int count=0;
        for (int i=0;i<n;i++) {
            if (!vis[i]) {
                count++;              
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};