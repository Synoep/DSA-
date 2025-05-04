class Solution {
public:
    int maximumGap(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       if(nums.size()==1) return 0;
       int max = INT_MIN;
       for(int i=0;i<nums.size()-1;i++){
        if((nums[i+1]-nums[i]) > max){
            max = nums[i+1]-nums[i];
        }
    }
    return max;
    }
};