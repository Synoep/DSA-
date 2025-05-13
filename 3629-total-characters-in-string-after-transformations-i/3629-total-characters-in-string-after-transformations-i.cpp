class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD=1'000'000'007;
        vector<long long> v(26, 0);
        for (char ch:s) v[ch-'a']++;
        for (int i=0;i<t;i++) {
            long long num=v[25];
            for (int j=25;j>=1;j--) v[j]=v[j-1];
            v[0] = num;
            v[1] = (v[1]+num)%MOD;
        }
        long long sum=0;
        for (int i=0;i<26;i++) {
            sum=(sum+v[i])%MOD;
        }
        return static_cast<int>(sum);
    }
};
