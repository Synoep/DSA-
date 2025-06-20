class Solution {
public:
    int maxDistance(string v, int k) {
        int maxi=0;
        int n=0,s=0,w=0,e=0;
        for(int i=0;i<v.size();i++){
             if(v[i]=='N') n++;
            if(v[i]=='W')  w++;
            if(v[i]=='E') e++;
             if(v[i]=='S') s++;
             int dist=abs(n-s)+abs(e-w)+2*k;
             maxi=max(maxi,min(dist,i+1));
        }
        return maxi;
    }
};