class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        const int total_sum=accumulate(time.begin(),time.end(),0);
        vector<int> pre(n+1);
        for (int i=0;i<n;i++) pre[i+1]=pre[i]+time[i];
        auto getSum = [&](int l, int r) {
            if (l>r) return 0;
            return pre[r+1]-pre[l];
        };
        const int NP = 1e8;
        vector dp(n+1,vector(n, vector(k+1,vector(total_sum+1,NP))));
        dp[1][0][0][time[0]]=time[0]*(position[1] - position[0]);
    
        for (int i=1;i<n-1;i++) {
            for (int last=0;last<i;last++) {
                for (int rem = 0;rem<=k;rem++) {
                    for (int last_sum =0;last_sum<=total_sum;last_sum++) {
                        if (dp[i][last][rem][last_sum] == NP) continue;
                        int dist=position[i+1]-position[i];
                        int timeSum = getSum(last+1,i);
                        dp[i + 1][i][rem][timeSum] =min(dp[i+1][i][rem][timeSum], dp[i][last][rem][last_sum]+dist*timeSum);
                        if (rem<k) {
                            dp[i+1][last][rem+1][last_sum] = min(dp[i+1][last][rem+1][last_sum], dp[i][last][rem][last_sum] + dist * last_sum);
                        }
                    }
                }
            }
        }
        int ans = NP;
        for (int last=0;last<n-1;last++) {
            for (int last_sum=0;last_sum <=total_sum;last_sum++) {
                ans = min(ans,dp[n-1][last][k][last_sum]);
            }
        }
        return ans;
    }
};