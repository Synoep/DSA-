class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int k=nums.size()/3;
        vector<int> v;
        for(auto a:nums) mp[a]++;
        for(auto a:mp) if(a.second>k) v.push_back(a.first);
        return v;
    }
};