class Solution {
public:
    // int d(int i,int j,vector<vector<int>>& t,int n,vector<vector<int>> &dp){
    //     // memo
    //     if(i==n-1) return t[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down=t[i][j]+ d(i+1,j,t,n,dp);
    //     int di=t[i][j]+ d(i+1,j+1,t,n,dp);
    //     return dp[i][j]=min(down,di);
    // }


    int minimumTotal(vector<vector<int>>& t) {
        // tabulation 
        int n=t.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[n-1][j]=t[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=t[i][j]+ dp[i+1][j];
                int di=t[i][j]+ dp[i+1][j+1];
                dp[i][j]=min(down,di);
            }
        }
        return dp[0][0];
    }
};