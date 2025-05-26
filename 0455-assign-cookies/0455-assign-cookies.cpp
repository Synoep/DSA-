class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=s.size();
        int count=0;
        if(n==0) return 0;
        for(int i=g.size()-1;i>=0;i--){
            if(n==0) return count;
            if(g[i]<=s[n-1] &&n>0){
                count++;
                n--;
            }
            
        }
     return count;  
    }
};