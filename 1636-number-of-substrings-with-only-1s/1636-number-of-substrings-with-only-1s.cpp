class Solution {
public:
    int numSub(string s) {
        int total=0,count=0;
        int mod=1e9+7;
        for(auto a:s){
            if(a=='1') count+=1;
            else count=0;
            total=(total+count)%mod;
        }
        return total;
    }
};