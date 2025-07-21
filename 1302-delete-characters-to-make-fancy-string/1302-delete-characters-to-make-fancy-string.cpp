class Solution {
public:
    string makeFancyString(string s) {
        vector<int>v;
        for(int i=2;i<s.size();i++){
            if(s[i]==s[i-2]&&s[i]==s[i-1]) v.push_back(i);
        }
        for (int i = v.size()-1;i>=0;i--) s.erase(v[i], 1);
        return s;
    }
};
