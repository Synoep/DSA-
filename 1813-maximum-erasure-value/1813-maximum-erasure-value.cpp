class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> seen;
        int left=0;
        int curr=0;
        int maxi=0;
        for (int right=0;right<n;right++) {
            while (seen.find(nums[right]) != seen.end()) {
                curr -=nums[left];
                seen.erase(nums[left]);
                left++;
            }
            curr += nums[right];
            seen.insert(nums[right]);
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};