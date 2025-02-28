class Solution {
public:
    vector<vector<int>> dp;
    int n, m;
    string s1, s2;

    int rec(int p1, int p2) {
        if (p1 == n) return m - p2;
        if (p2 == m) return n - p1;

        int &ret = dp[p1][p2];
        if (~ret) return ret;

        if (s1[p1] == s2[p2]) 
            return ret = 1 + rec(p1 + 1, p2 + 1);
        
        return ret = min(rec(p1 + 1, p2), rec(p1, p2 + 1)) + 1;
    }

    string build(int p1, int p2) {
        string ans;
        while (p1 < n && p2 < m) {
            if (s1[p1] == s2[p2]) {
                ans += s1[p1];
                p1++, p2++;
            } else if (dp[p1 + 1][p2] + 1 == dp[p1][p2]) {
                ans += s1[p1++];
            } else {
                ans += s2[p2++];
            }
        }
        return ans + s1.substr(p1) + s2.substr(p2);
    }

    string shortestCommonSupersequence(string str1, string str2) {
        n = str1.size();
        m = str2.size();
        s1 = str1;
        s2 = str2;

        dp.assign(n + 1, vector<int>(m + 1, -1));
        rec(0, 0);
        return build(0, 0);
    }
};