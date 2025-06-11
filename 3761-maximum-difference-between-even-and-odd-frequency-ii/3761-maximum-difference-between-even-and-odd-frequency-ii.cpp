class Solution {
public:
    int hd(int a, int b, int c, vector<vector<int>>& d) {
        int e[2][2];
        e[0][0] =e[0][1]=e[1][1]=e[1][0]=1e5;
        int f=0,g=c;
        auto& h=d[a];
        auto& i=d[b];
        int j=INT_MIN;
        int k=h.size();
        while (g<k) {
            int l=h[g], m =i[g];
            int n=h[f], o =i[f];
            if (m!=o) {
                while (g-f>= c) {
                    int p =o%2,q=n%2;
                    e[q][p] =min(e[q][p],n-o);
                    f++;
                    n =h[f],o=i[f];
                }
            }
            int r =l-m-e[1-(l%2)][m % 2];
            j = max(j,r);
            g++;
        }
        return j;
    }

    int maxDifference(string a, int b) {
        int c = a.size();
        vector<vector<int>> d(5,vector<int>(c+1));
        for (int e =0;e<c;e++) {
            for (int f=0;f<5; f++) d[f][e+1]=d[f][e];
            d[a[e]-'0'][e+1]++;
        }
        int g = INT_MIN;
        for (int h=0;h<5;h++) {
            if (!d[h][c]) continue;
            for (int i =0;i<5;i++) {
                if (!d[i][c]||h == i) continue;
                g = max(g, hd(h,i,b,d));
            }
        }
        return g;
    }
};
