class Solution {
public:
    int d(int n,int ind,int prev,vector<int>& nums,vector<vector<int>> &dp){
        if(ind>n-1) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int ntake=d(n,ind+1,prev,nums,dp);
        int take=0;
        if(prev==-1 || nums[ind]>nums[prev] ) take=1+d(n,ind+1,ind,nums,dp);
        dp[ind][prev+1]=max(ntake,take);
        return dp[ind][prev+1];


    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return d(n,0,-1,nums,dp);
    }
};