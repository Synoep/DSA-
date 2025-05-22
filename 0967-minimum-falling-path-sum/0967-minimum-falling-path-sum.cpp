class Solution {
public:
    // int d(int i, int j , int m,vector<vector<int>>& matrix,vector<vector<int>> &dp){
    //     // memo
    //     if(i<0||j<0 ||j>=m) return 1e9;
    //     if(i==0) return matrix[i][j];
    //     if(dp[i][j] !=-1) return dp[i][j];
    //     int up=matrix[i][j]+d(i-1,j,m,matrix,dp);
    //     int ld=matrix[i][j]+d(i-1,j-1,m,matrix,dp);
    //     int rd=matrix[i][j]+d(i-1,j+1,m,matrix,dp);
    //     return min(up,min(ld,rd));

    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++) dp[n-1][j]=matrix[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int up=matrix[i][j]+dp[i+1][j];
                int ld=matrix[i][j];
                if(j>0) ld+=dp[i+1][j-1];
                else ld+=1e9;
                int rd=matrix[i][j];
                if(j<m-1) rd+=dp[i+1][j+1];
                else rd+=1e9;
                dp[i][j]=min(up,min(ld,rd));
            }
        }
    int mini = INT_MAX;
    for (int j=0;j<m;j++) {
        mini=min(mini,dp[0][j]);
    }
    return mini;
    }
};