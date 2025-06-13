class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mini=*min_element(complexity.begin(),complexity.end());
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]==mini)
            return 0;
        }
        int mod=static_cast<int>(1e9+7);
        int ans=1;
        for(int i=2;i<complexity.size();i++)
        ans=(ans*1LL*i)%mod;
        return ans;
    }
};