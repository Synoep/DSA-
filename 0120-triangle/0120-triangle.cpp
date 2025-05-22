class Solution {
public:
    int d(int i,int j,vector<vector<int>>& t,int n,vector<vector<int>> &dp){
        // memo
        if(i==n-1) return t[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=t[i][j]+ d(i+1,j,t,n,dp);
        int di=t[i][j]+ d(i+1,j+1,t,n,dp);
        return dp[i][j]=min(down,di);
    }


    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return d(0,0,t,n,dp);
    }
};