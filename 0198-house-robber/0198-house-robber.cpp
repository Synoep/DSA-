class Solution {
public:
    int d(int ind,vector<int>& nums,vector<int> &dp){
        //memo
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
        int take=d(ind-2,nums,dp) +nums[ind];
        int non=d(ind-1,nums,dp)+0;
        return dp[ind]= max(take,non);
    }
 
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return d(n-1,nums,dp);
    }
};