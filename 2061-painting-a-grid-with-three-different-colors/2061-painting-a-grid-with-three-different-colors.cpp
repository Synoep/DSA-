class Solution {
public:
    const int MOD = 1e9 + 7;    
void genPatterns(int m, vector<vector<int>> &patterns, vector<int> &cur) {
        if (cur.size()==m) {
            patterns.push_back(cur);
            return;
        }
        for (int c=0;c<3;c++) {
            if (cur.empty()||cur.back()!=c) {
                cur.push_back(c);
                genPatterns(m,patterns,cur);
                cur.pop_back();
            }
        }
    }
    
    int colorTheGrid(int m,int n) {
        vector<vector<int>> patterns;
        vector<int> cur;
        genPatterns(m,patterns,cur);
        int p=patterns.size();
        vector<vector<int>> compatible(p);
        for (int i=0;i<p;i++) {
            for (int j=0;j<p;j++) {
                bool ok =true;
                for (int k=0;k<m;k++) {
                    if (patterns[i][k]==patterns[j][k]) {
                        ok=false;
                        break;
                    }
                }
                if (ok) compatible[i].push_back(j);
            }
        }
        vector<int> dp(p,1);
        for (int col =1;col<n;col++) {
            vector<int> newDP(p, 0);
            for (int i=0;i<p;i++) {
                for (int j:compatible[i]) {
                    newDP[j]=(newDP[j] +dp[i])%MOD;
                }
            }
            dp = newDP;
        }
        int res=0;
        for (int x:dp) res =(res+x)%MOD;
        return res;
    }
};