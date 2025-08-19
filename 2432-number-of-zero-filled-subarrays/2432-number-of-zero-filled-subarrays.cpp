class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long  count =0,s=0;
        for(auto a:nums){
            if(a==0){
                s++;
                count+=s;
            }
            else s=0;
        }
        return count;
    }
};