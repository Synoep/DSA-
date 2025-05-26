class Solution {
public:
    int d(int n,int k,vector<int> &coins,vector<vector<int>> &dp){
        if(k==0) return 0;
        if (n==0){
            if(k%coins[0]==0) return k/coins[0];
            else return 1e9;
        }; 
        if(dp[n][k]!=-1) return dp[n][k];
        int ntake=0+d(n-1,k,coins,dp);
        int take=1e9;
        if(coins[n]<=k){
            take=1+d(n,k-coins[n],coins,dp);
        }
        return dp[n][k]=min(ntake,take);

    }
    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
       int ans= d(n-1,amount,coins,dp);
       if(ans>=1e9) return -1;
       else return ans;
    }
};