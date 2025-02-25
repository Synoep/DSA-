class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        long long o=0,e=1,s=0,r=0;
        for(int a:arr){
            s+=a;
            if(s%2==0){
                r=(r+o)%MOD;
                e++;
            }else{
                r=(r+e)%MOD;
                o++;
            }
        }return r;
    }
};