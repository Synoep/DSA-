class Solution {
public: 
    int rob(vector<int>& nums) {
        // space optimize
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        int curr=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];if(i>1) pick+=prev2;
            int non=0+prev1;
            curr=max(pick,non);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};