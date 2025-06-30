class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0;
        int maxi=0;        
        for (int right=0;right<nums.size();right++) {
            while (nums[right]-nums[left]>1) left++;
            if (nums[right]-nums[left]==1)maxi=max(maxi,right-left+1);
        }
        return maxi;
    }
};
// 1122    