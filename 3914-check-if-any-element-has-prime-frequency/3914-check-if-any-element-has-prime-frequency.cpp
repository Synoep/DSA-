class Solution {
public:
    bool p(int n) {
    if (n <= 1) return false; 
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) return false; 
    }
    return true; 
}
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int ,int>mp;
        bool f=false;
        for(auto a:nums) mp[a]++;
        for(auto a:mp){
            if(p(a.second)==true){
                f=true;
                break;
            }
        }
        return f;
    }
};