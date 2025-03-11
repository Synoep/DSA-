class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int left=0,right=0,maxi=0;
        for(int i=0;i<k;i++){
            left+=v[i];
        }
        maxi=left;
        int rindex=v.size()-1;
        for(int i=k-1;i>=0;i--){
            left-=v[i];
            right+=v[rindex];
            rindex-=1;
            maxi=max(maxi,left+right);
        }
        return maxi;
    }
};