class Solution {
public:
    int d(int ind, int k, vector<int> &arr,vector<vector<int>> &dp){
     
    if(k==0) return true;
    if(ind ==0) return arr[0] ==k;
    if(dp[ind][k]!=-1) return dp[ind][k];

    bool ntake=d(ind-1,k,arr,dp);
    bool take=false;
    if(k>=arr[ind]){
        take=d(ind-1,k-arr[ind],arr,dp);

    }
    return dp[ind][k]=take||ntake;

}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(target+1,-1));
        return d(nums.size()-1,target,nums,dp);

    }
};