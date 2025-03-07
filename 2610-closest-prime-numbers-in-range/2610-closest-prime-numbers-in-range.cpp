class Solution {
    bool pr(int n){
        if (n<2) return false;
        for (int i=2;i*i<=n;i++) {
        if (n%i==0) return false;
    }
    return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
      vector<int> v;
        for(int i=left;i<=right;i++){
            if(pr(i)){
             v.push_back(i);
        }
        }
        if(v.size()<2) return {-1,-1}; 
        int mini=INT_MAX;
        vector<int>ans(2);
        for(int i=1;i<v.size();i++){
            int diff=v[i]-v[i-1];
            if(mini>diff){
              mini=diff;
              ans[0]=v[i-1];
              ans[1]=v[i];
            }
        }
        return ans;

    }
};