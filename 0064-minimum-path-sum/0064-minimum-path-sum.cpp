class Solution {
public:
    int d(int m, int n ,vector<vector<int>>& grid,vector<vector<int>> &dp){
        //memo
        if(m==0 && n==0) return grid[m][n];
        if(m<0||n<0) return 1e9;
        if(dp[m][n]!=-1) return dp[m][n];
        int up =grid[m][n]+d(m-1,n,grid,dp);
        int l=grid[m][n]+d(m,n-1,grid,dp);
        return dp[m][n]=min(up,l);
    }

    int minPathSum(vector<vector<int>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> dp(m,vector<int>(n,-1));
       return d(m-1,n-1,grid,dp);
    }
};