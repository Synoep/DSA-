class Solution {
public:
    int rob(vector<int>& nums) {
        // Tabulation
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>nums1(nums.begin(),nums.end()-1);
        vector<int>nums2(nums.begin()+1,nums.end());
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1); 
        dp1[0]=nums1[0];
        dp2[0]=nums2[0];
        for(int i=1;i<n-1;i++){
            int take1=nums1[i];if(i>1) take1+=dp1[i-2];
            int non1=dp1[i-1];
            dp1[i]=max(take1,non1);
            int take2=nums2[i];if(i>1) take2+=dp2[i-2];
            int non2=dp2[i-1];
            dp2[i]=max(take2,non2);
        }
        return max(dp1[n-2],dp2[n-2]);
    }
};