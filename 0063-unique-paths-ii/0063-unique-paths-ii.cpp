class Solution {
public:
    int d(int m, int n,vector<vector<int>>& o,vector<vector<int>> &dp){
        //memo
        if(m==0 && n==0 && o[m][n]!=1) return 1;
        if(m<0 || n<0) return 0;
        if(o[m][n]==1) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int up=d(m-1,n,o,dp);
        int l=d(m,n-1,o,dp);
        return dp[m][n]=l+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return d(m-1,n-1,obstacleGrid,dp);
    }
};