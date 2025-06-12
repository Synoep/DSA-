class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int a=abs(nums[n-1] -nums[0]);
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            int v=abs(nums[i]-nums[i+1]);
            maxi=max(maxi,v);
        }
        maxi=max(maxi,a);
        return maxi;
    }
};