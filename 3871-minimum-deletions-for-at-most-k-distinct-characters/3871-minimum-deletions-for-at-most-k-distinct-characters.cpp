class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> v(26,0);
        for(auto x:s) v[(x-'a')]++;
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<26-k;i++) ans +=v[i];
        return ans;
    }
};