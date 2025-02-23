class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        string v;
        while(n>2){
            string a;
            for(int i=0;i<n-1;i++){
                a+=to_string(((s[i]-'0')  + (s[i+1]-'0')) %10);
            }
            n=n-1;
            s=a;
        }
        if(s[0]==s[1]) return true;
        else return false;
    }
};