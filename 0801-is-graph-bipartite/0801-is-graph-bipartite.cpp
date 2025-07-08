class Solution {
public:
    bool dfs(int node,int c,vector<int> &color,vector<vector<int>> &adj){
        color[node]=c;
        for(auto a:adj[node]){
            if(color[a]==-1) {
                if(dfs(a,!c,color,adj)==false) return false;
            }
            else if(color[a]==c) return false; 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
       int v=graph.size();
       vector<int> color(v,-1);
       for(int i=0;i<v;i++){
           if(color[i]==-1){
             if(dfs(i,0,color,graph)==false) return false;
           }
       }
       return true;
    }
};