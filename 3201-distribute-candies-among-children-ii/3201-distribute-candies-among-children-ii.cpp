class Solution {
public:
    long nC2(int n){ return (long)(n+2)*(n+1)/2; };
    long long distributeCandies(int n, int limit) {
        long long res = nC2(n); 
        if(limit+1<=n) res-=3*nC2(n-limit-1);
        if(2*limit+2<=n) res+=3*nC2(n-2*limit-2);
        if(3*limit+3<=n) res-=nC2(n-3*limit-3);
        return res;
    }
};