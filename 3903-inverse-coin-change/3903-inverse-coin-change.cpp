class Solution {
public:
    int d(int target , vector<int>& v){
        vector<int> dp(target+1,0);
        dp[0]=1;
        for( auto a:v){
            for(int i=1;i<=target;i++){
                if(i-a<0) continue;
                dp[i]+=dp[i-a];
            }
        }
        return dp[target];
    }
    vector<int> findCoins(vector<int>& a) {
        vector<int> v;
        for(int i=0;i<a.size();i++){
            int count=d(i+1,v);
            if(count>a[i]) return {};
            if(count==a[i]-1) v.push_back(i+1);
            else if(count==a[i]) continue;
            else return {}; 
        }
        return v;
    }
};