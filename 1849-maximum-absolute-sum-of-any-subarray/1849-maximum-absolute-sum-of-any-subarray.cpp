class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int cmax=0,ms=0,cmin=0,mins=0;
        for(auto a:nums){
            cmax=max(a,cmax+a);
            cmin=min(a,cmin+a);
            ms=max(ms,cmax);
            mins=min(mins,cmin);
        }
        return max(ms,abs(mins));
    }
};