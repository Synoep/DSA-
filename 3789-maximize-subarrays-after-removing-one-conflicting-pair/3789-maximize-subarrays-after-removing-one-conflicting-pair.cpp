class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<long long>> conflicts(n+2);
        for(const auto& pair:conflictingPairs){
            int a=pair[0];
            int b=pair[1];
            if(a<b) conflicts[b].push_back(a);
            else conflicts[a].push_back(b);
        }
        int maxleft=0;
        int secondmaxleft=0;
        vector<long long> gains(n+2,0);
        long long validsubarray=0;
        for(int right=1; right<=n; ++right){
            for(int left:conflicts[right]){
                if(left>maxleft){
                    secondmaxleft=maxleft;
                    maxleft=left;
                }
                else if(left>secondmaxleft) secondmaxleft=left;
            }
            validsubarray+=right-maxleft;
            gains[maxleft]+=maxleft-secondmaxleft;
        }
        long long maxgain=*max_element(gains.begin(),gains.end());
        return validsubarray+maxgain;
        // error .....
    }
};