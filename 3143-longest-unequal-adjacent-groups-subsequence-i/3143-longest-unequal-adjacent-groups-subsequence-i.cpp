class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w,vector<int>& g) {
        vector<string> s;
        if(w.size()==0) return s;
        s.push_back(w[0]);
        for(int i=1;i<w.size();i++){
             if(g[i]!=g[i-1]) s.push_back(w[i]);
        } 
        return s;
    }
};