class Solution {
public:
   const int mod=1e9+7;
    vector<int> Power(int n) {
        vector<int> power(n+1,1);
        for (int i=1;i<=n;i++) {
            power[i]=(power[i-1]*2LL)%mod;
        }
        return power;
    }
    int numSubseq(vector<int>& nums, int target) {
        // long long mod=1e9+7;
        sort(nums.begin(),nums.end());
        long  left =0,right=nums.size()-1;
        long long total=0;
        int n=nums.size();
        vector<int>power=Power(n);
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                total=(total+power[right-left])%mod;
                left++;
            }
            // else if(nums[left]+nums[right]>target) right--;
            else right--;
        }
        return total;
    }
};