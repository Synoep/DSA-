class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>set;
        for(int n:nums) set.insert(n);
        int n=set.size(),ln=nums.size();
        unordered_map<int,int>mp;
        int l=0,r=0,res=0;
        while(r<ln){
            mp[nums[r]]++;
            while(l<=r && mp.size()==n){
                res+=ln-r;
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return res;
    }
};