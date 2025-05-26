class Solution {
public:
    int c(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind ==0) {
        if (target==0&&arr[0]==0)
            return 2;
        if (target == 0||target==arr[0])
            return 1;
        return 0; 
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int ntake=c(ind-1,target,arr,dp);
    int taken=0;
    if (arr[ind] <=target)
        taken = c(ind-1,target-arr[ind], arr, dp);
    return dp[ind][target] =(ntake+taken);
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size(); 
    int sum=0;
    for (int i=0;i<nums.size();i++) {
        sum+= nums[i];
    }
    if (sum-target<0)
        return 0;
    if ((sum- target)%2==1)
        return 0; 
    int s2 =(sum-target)/2; 
    
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1)); 
    return c(n-1,s2,nums,dp);
    }
};