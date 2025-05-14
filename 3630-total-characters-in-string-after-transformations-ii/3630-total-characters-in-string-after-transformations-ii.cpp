using ll=long long;

class Solution {
public:
    const int m=1e9+7;

    vector<vector<ll>> a(const vector<vector<ll>> &x,const vector<vector<ll>> &y){
        int r=x.size(),c=x[0].size(),d=y[0].size();
        vector<vector<__int128_t>> z(r,vector<__int128_t>(d,0));
        vector<vector<ll>> o(r,vector<ll>(d,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<d;j++){
                for(int k=0;k<c;k++){
                    z[i][j]+=x[i][k]*y[k][j];
                }
                o[i][j]=z[i][j]%m;
            }
        }
        return o;
    }

    vector<vector<ll>> b(vector<vector<ll>> v,ll e){
        vector<vector<ll>> w(v.size(),vector<ll>(v.size(),0));
        for(int i=0;i<v.size();i++)w[i][i]=1;
        while(e>0){
            if(e%2==1)w=a(w,v);
            v=a(v,v);
            e/=2;
        }
        return w;
    }

    int lengthAfterTransformations(string s,int t,vector<int>& n){
        vector<vector<ll>> f(26,vector<ll>(26,0));
        for(int i=0;i<26;i++){
            for(int j=0;j<n[i];j++){
                f[i][(i+1+j)%26]++;
            }
        }
        f=b(f,t);
        vector<vector<ll>> g(1,vector<ll>(26,0));
        for(char ch:s) g[0][ch-'a']++;
        
        g=a(g,f);
        int l=0;
        for(int x:g[0]){
            l+=x;
            if(l>=m)l-=m;
        }
        return l;
    }
};
