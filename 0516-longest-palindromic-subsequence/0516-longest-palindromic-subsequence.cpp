class Solution {
public:
    // int d(int n,int m,string s,vector<vector<int>> &dp){
        // memo
    //     if(m==n) return 1;
    //     if(n>m) return 0;
    //     if(dp[n][m]!=-1) return dp[n][m];
    //     if(s[n]==s[m]) return dp[n][m]=2+d(n+1,m-1,s,dp);
    //     return dp[n][m]=max(d(n+1,m,s,dp),d(n,m-1,s,dp));
    // }
    int longestPalindromeSubseq(string s1) {
        // tabulation
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    
    }
};