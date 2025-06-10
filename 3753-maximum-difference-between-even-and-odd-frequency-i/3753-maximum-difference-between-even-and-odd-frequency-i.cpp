class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int ,int> mp;
        for(auto a:s) mp[a]++;
        int maxi=INT_MIN,maxii=INT_MAX;
        for(auto a:mp){
           if(a.second%2!=0) maxi=max(maxi,a.second);
           if(a.second%2==0) maxii=min(maxii,a.second);
        }
        return maxi-maxii;
    }
};