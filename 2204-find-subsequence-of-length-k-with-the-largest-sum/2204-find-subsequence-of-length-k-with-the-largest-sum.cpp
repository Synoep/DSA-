class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>sorted=nums;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int>v;
        for(int i=0;i<k;i++){
           v.push_back(nums[i]);
        }
        unordered_map<int,int>mp;
        for(auto a:v) mp[a]++;
        vector<int>ans;
        for(int i=0;i<sorted.size();i++){
            if(mp[sorted[i]]>0){
                 ans.push_back(sorted[i]);
                 mp[sorted[i]]--;
            }
        }        
        return ans;
    }
};