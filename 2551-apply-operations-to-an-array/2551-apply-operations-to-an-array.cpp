class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        int index=0;
         for(int i=0;i<n;i++){
             if(nums[i]!=0) {
                swap(nums[i],nums[index]);
               index++;
             }
        }
      
    return nums;
    }
};