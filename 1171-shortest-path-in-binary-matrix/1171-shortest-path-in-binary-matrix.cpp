class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (n == 1 &&grid[0][0]==0) return 1;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        q.push({1,{0,0}}); // dis, row col
        vector<int> dr = {-1,-1,-1,0,0,1,1,1};
        vector<int> dc = {-1,0,1,-1,1,-1,0,1};
        if(grid[n-1][n-1]==1||grid[0][0]==1) return -1;
        dis[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int distance=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<8;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr<n&&nc<n&&nr>=0&&nc>=0&&grid[nr][nc]==0&&distance+1<dis[nr][nc]){
                    dis[nr][nc]=1+distance;
                    if(nr==n-1&&nc==n-1) return dis[nr][nc] ;
                    q.push({1+distance,{nr,nc}});
                }
            }
        }
        return -1;
    }
};