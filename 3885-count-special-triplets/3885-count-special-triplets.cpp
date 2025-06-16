class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD=1e9+7;
        unordered_map<int,int>l,r;
        for(int a:nums){
            r[a]++;
        }
        long long ans=0;
        int n=nums.size();
        for(int j=0;j<n;j++){
            r[nums[j]]--;
            int t=nums[j]*2;
            long long  left=l[t];
            long long  right=r[t];
            ans=(ans+(left*right)) %MOD;
            l[nums[j]]++;
        }
       return ans;
    }
};