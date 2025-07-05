class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto a:arr) mp[a]++;
        int maxi=0;
        for(auto a:mp){
            if(a.first==a.second) maxi=max(maxi,a.first);
        }
     if(maxi==0) return -1;
     return maxi;
    }
};