class Solution {
public:
    int d(int ind,vector<int> &nums,vector<int> &dp){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int take=nums[ind]+d(ind-2,nums,dp);
        int non=d(ind-1,nums,dp);
        return dp[ind]=max(take,non);
    }
    int rob(vector<int>& nums) {
        // memo
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>nums1(nums.begin(),nums.end()-1);
        vector<int>nums2(nums.begin()+1,nums.end());
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1); 
        nums.pop_back();
        int a=d(n-2,nums1,dp1);
        int b=d(n-2,nums2,dp2);
        return max(a,b);
    }
};