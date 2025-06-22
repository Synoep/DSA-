class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int a=0;
        if(s.length()%k!=0){
             a=s.length()%k;
             for(int i=0;i<k-a;i++) s+=fill;
        } 
        vector<string>b;
        for(int i=0;i<s.length();i+=k){
            b.push_back(s.substr(i, k));
        }
        return b;
    }
};