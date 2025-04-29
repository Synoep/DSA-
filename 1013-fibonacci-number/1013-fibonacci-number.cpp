class Solution {
    vector<int> dp = vector<int>(31, -1); 
public:
    int fib(int n) {
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fib(n-1)+fib(n-2);
    }
};