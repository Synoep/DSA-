class Solution {
public:
    int d(int n,int k,vector<int> &coins,vector<vector<int>> &dp){
        // if(k==0) return 0;
        if (n==0){
            if(k%coins[0]==0) return 1;
            else return 0;
        }; 
        if(dp[n][k]!=-1) return dp[n][k];
        int ntake=d(n-1,k,coins,dp);
        int take=0;
        if(coins[n]<=k){
            take=d(n,k-coins[n],coins,dp);
        }
        return dp[n][k]=ntake+take;

    }
    int change(int amount, vector<int>& coins) {
       int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans= d(n-1,amount,coins,dp);
        return ans;
    }
};