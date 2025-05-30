class Solution {
public:
    // int d(int n,int ind,int prev,vector<int>& nums,vector<vector<int>> &dp){
    //     if(ind>n-1) return 0;
    //     if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    //     int ntake=d(n,ind+1,prev,nums,dp);
    //     int take=0;
    //     if(prev==-1 || nums[ind]>nums[prev] ) take=1+d(n,ind+1,ind,nums,dp);
    //     dp[ind][prev+1]=max(ntake,take);
    //     return dp[ind][prev+1];


    // }
    int lengthOfLIS(vector<int>& nums) {
        // BS
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=0;i<n;i++){
            if(nums[i]>temp.back()) temp.push_back(nums[i]);
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};