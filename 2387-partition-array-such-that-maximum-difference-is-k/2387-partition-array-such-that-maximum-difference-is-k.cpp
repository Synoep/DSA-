class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int count=1;
        vector<int>v(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]-mini<=k) continue;
            else {
                mini=nums[i];
                count++;
            }
        }
        return count;
    }
};