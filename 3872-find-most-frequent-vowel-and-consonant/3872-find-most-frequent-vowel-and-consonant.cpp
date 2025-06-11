class Solution {
public:
    int maxFreqSum(string s) {
        vector<bool> vowel(26, false);
        for (char c :{'a', 'e','i','o','u'}) {
            vowel[c -'a']=true;
        }
        
        vector<int> vow(26,0);
        vector<int> cons(26,0);
        
        for (char ch : s) {
            int idx = ch-'a';
            if (vowel[idx]) {
                vow[idx]++;
            } else  cons[idx]++;
            
        }
        
        int maxv=0, maxi=0;
        
        for (int i=0;i<26;i++) {
            maxv=max(maxv, vow[i]);
            maxi=max(maxi, cons[i]);
        }
        
        return maxv+maxi;
    }
};
