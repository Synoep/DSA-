class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int time) {
        int n = grid.size(), m = grid[0].size();
        if (i<0||j<0||i>=n||j>=m) return;
        if (grid[i][j]==0||(grid[i][j] != 1&&grid[i][j]<time)) return;
        grid[i][j]=time;
        dfs(grid, i+1,j,time+1);
        dfs(grid,i-1,j,time+1);
        dfs(grid,i,j+1,time+1);
        dfs(grid,i,j-1,time+1);

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j]==2) {
                    dfs(grid, i,j,2);
                }
            }
        }
        int maxi=0;
        for (auto& row:grid) {
            for (int cell :row) {
                if (cell==1) return -1; 
                maxi= max(maxi,cell);
            }
        }
        if(maxi>2) return maxi-2;
        return 0;
    }
};