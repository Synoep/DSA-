class Solution {
public:
    // int d(int m, int n ,vector<vector<int>>& grid,vector<vector<int>> &dp){
    //     //memo
    //     if(m==0 && n==0) return grid[m][n];
    //     if(m<0||n<0) return 1e9;
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int up =grid[m][n]+d(m-1,n,grid,dp);
    //     int l=grid[m][n]+d(m,n-1,grid,dp);
    //     return dp[m][n]=min(up,l);
    // }

    int minPathSum(vector<vector<int>>& grid) {
       //Tabulation
       int m=grid.size();
       int n=grid[0].size();
       vector<vector<int>> dp(m,vector<int>(n,0));
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) dp[i][j]=grid[i][j];
            else {
            int up=grid[i][j];
            if(i>0) up+=dp[i-1][j];
            else up+=1e9;
            int l=grid[i][j];
            if(j>0) l+=dp[i][j-1];
            else l+=1e9;
            dp[i][j]=min(up,l);
            }
        }
       }
       return dp[m-1][n-1];
    }
};