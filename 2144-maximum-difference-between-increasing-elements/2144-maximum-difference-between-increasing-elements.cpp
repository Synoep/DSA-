class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=-1;
        int num=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>num) maxi=max(maxi,nums[i]-num);
            else num=nums[i];
        }
        return maxi;
    }
};