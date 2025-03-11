class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int left=0;
        int maxf=0,maxl=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxf=max(maxf,mp[s[i]]);
            while((i-left+1)-maxf>k){
                mp[s[left]]--;
                left++;
            }
            maxl=max(maxl,i-left+1);
        }
        return maxl;
    }
};