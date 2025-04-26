class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long in=-1;
        long long maxi=-1,mini=-1;
        long long count=0;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<minK ||nums[i]>maxK) in=i;
        if(nums[i]==minK) mini=i;
        if(nums[i]==maxK) maxi=i;
         long long valid=min(mini,maxi);
         if(valid>in) count+=valid-in;
       }
       return count;

    }
};