class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<nums.size();i++){
              if(i==nums.size()-1 || i==nums.size()-2) break;
              if(nums[i]+nums[i+2]==nums[i+1]/2&& nums[i+1]%2==0) count++;    
        }
        return count;
    }
};