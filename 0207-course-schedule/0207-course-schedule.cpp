class Solution {
public:
    bool dfs(int src,vector<vector<int>> &adj,vector<int> &vis,vector<int> &df){
        vis[src]=1;
        df[src]=1;
            for(auto a: adj[src]) {
                if(!vis[a]){
                    if(dfs(a,adj,vis,df)==true) return true;
                }
                else if(df[a]) {
                    return true;
                }
            }
            df[src]=0;
            return false;
        }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        for(auto a:p){
            int u=a[0],v=a[1];
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        vector<int>df(n,0);
        // dfs(1,adj,st,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) 
              if(dfs(i,adj,vis,df)) return false;
        }
        return true;
    }
};