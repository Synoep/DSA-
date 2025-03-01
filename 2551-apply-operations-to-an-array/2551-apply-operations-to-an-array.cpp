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
        vector<int>v;
        for(int i=0;i<n;i++){
             if(nums[i]!=0) v.push_back(nums[i]);
        }
        while(v.size()<n) v.push_back(0);
    return v;
    }
};