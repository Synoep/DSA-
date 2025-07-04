class Solution {
public:
    #define ll long long
    int countsteps(int n,int k,ll prefix1,ll prefix2){
        int steps=0;
        while(prefix1<=n){
            steps+=min(1LL*(n+1),prefix2)-prefix1;
            prefix1*=10;
            prefix2*=10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        ll curr=1;
        k-=1;
        while(k!=0){
            int steps=countsteps(n,k,curr,curr+1);
            if(steps<=k){
                curr++;
                k-=steps;
            }else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};