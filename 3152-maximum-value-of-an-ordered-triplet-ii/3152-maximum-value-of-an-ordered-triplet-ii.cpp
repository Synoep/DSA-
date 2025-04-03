class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0,maxe=0,maxdif=0;
        for(long long a:nums){
            maxi=max(maxi,maxdif*a);
            maxdif=max(maxdif,maxe-a);
            maxe=max(maxe,a);
        }
        return maxi;
    }
};