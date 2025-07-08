class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>> &vis){
        int n = grid.size(), m = grid[0].size();
        if (i<0||j<0||i>=n||j>=m||grid[i][j]!='1'|| vis[i][j])
                return;
        vis[i][j]=1;
        
        dfs(grid,i+1,j,vis);
        dfs(grid,i-1,j,vis);
        dfs(grid,i,j+1,vis);
        dfs(grid,i,j-1,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='1') dfs(grid,i,j,vis),count++;
            }
        }
        return count;
    }
};