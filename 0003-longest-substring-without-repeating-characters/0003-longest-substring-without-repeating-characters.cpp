class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int maxi=0;
        int left=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()&&mp[s[i]]>=left){
                left=mp[s[i]]+1;
            }
            mp[s[i]]=i;
             maxi=max(maxi,i-left+1);
        }
        return maxi;
    }
};