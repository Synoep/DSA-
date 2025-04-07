class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
             mp[nums[i]]++;
             maxi=max(maxi,mp[nums[i]]);
        }
        for(auto a:mp){
            if(a.second==maxi) count+=a.second;
        }
        return count;
    }
};