class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0,mid=0,high=nums.size()-1;
        while(mid<=high){
           if(nums[mid]==0) swap(nums[mid],nums[left]),mid++,left++;
           else if(nums[mid]==1) mid++;
           else swap(nums[mid],nums[high]), high--;
        }
    }
};