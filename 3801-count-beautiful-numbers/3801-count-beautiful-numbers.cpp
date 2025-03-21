class Solution {
public: 
int mod;
vector<int>lim;//digits of the limit but as an array lol
int dp[10][82][82][2];
int rec(int d, int cursum, int curprod, bool less){
    if(d==(int)lim.size()) return less && cursum == mod && curprod == 0;
    if(dp[d][cursum][curprod][less]!=-1)return dp[d][cursum][curprod][less];
    int en = less?9:lim[d];
    int ret = 0;
    for(int i = 0; i <= en; i++){
        if(cursum+i>mod)continue;
        ret += rec(d+1,cursum+i,cursum == 0 && i == 0 ? 1 : (curprod*i)%mod,less||(i<lim[d]));
    }
    return dp[d][cursum][curprod][less]= ret;
}
    int beautifulNumbers(int l, int r) { 
        vector<int>ldg,rdg; 
    while(l){
        ldg.push_back(l%10);
        l/=10;
    }
    ++r;
    while(r){
        rdg.push_back(r%10);
        r/=10;
    }
    reverse(ldg.begin(),ldg.end()),reverse(rdg.begin(),rdg.end());
    int ans = 0;
    for(mod = 1; mod <= 81; mod++){
        memset(dp,-1,sizeof(dp));
        lim=rdg;
        int res = rec(0, 0, 1, 0);
        memset(dp,-1,sizeof(dp));
        lim=ldg;
        res -= rec(0, 0, 1, 0);
        ans += res;
    } 
    return ans;
    }
};