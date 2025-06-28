class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v(256,-1);
        int left=0,maxi=0;
        for(int r=0;r<s.length();r++){
            if(v[s[r]]!=-1){
                left=max(left,v[s[r]]+1);
            }
            v[s[r]]=r;
            maxi= max(maxi,r-left+1);
        }
        return maxi;
    }
};