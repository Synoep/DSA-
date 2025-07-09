class Solution {
public:
    void dfs(vector<vector<int>>& mat, int i, int j,int m,int n, int time) {
        if (i<0||j<0||i>=n||j>=m) return;
        if (mat[i][j]==0 ||(mat[i][j]>0&&mat[i][j]<=time)) return;
        mat[i][j]=time;
        dfs(mat,i+1,j,m,n,time+1);
        dfs(mat,i-1,j,m,n,time + 1);
        dfs(mat,i,j+1,m,n,time+1);
        dfs(mat, i,j-1,m,n,time+1);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int n=mat.size(),m=mat[0].size();
         for (int i=0;i<n;i++)
            for (int j=0; j<m;j++)
                if (mat[i][j] == 1) mat[i][j] = 10000;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (mat[i][j]==0){
                    dfs(mat,i+1,j,m,n,1),
                    dfs(mat,i-1,j,m,n,1),
                    dfs(mat,i,j+1,m,n,1),
                    dfs(mat,i,j-1,m,n,1);
                }
        return mat;
    }
};