class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int s=0;
        int n=tops.size();
        unordered_map<int,int>tp;
        unordered_map<int,int>bp;
        int n1=0,n2=0;
        int maxi1=0,maxi2=0;
        for(int i=0;i<tops.size();i++) tp[tops[i]]++;
        for(int i=0;i<tops.size();i++) bp[bottoms[i]]++;
        for(auto &p:tp){
            if(p.second>maxi1){
                 n1=p.first;
                 maxi1=p.second;
            }
        }
        for(auto &p:bp){
            if(p.second>maxi2){
                 n2=p.first;
                 maxi2=p.second;
            }
        }
        int c1=0,c2=0;
        if (maxi1 >= maxi2) {
        for (int i=0;i<n;i++) {
        if (tops[i]!=n1) {
            if (bottoms[i]==n1) c1++;
            else return -1;
        }
    }
    return c1;
}   else {
    for (int i=0;i<n;i++) {
        if (bottoms[i]!=n2) {
            if (tops[i]==n2) c2++;
             else return -1;
        }
    }
    return c2;
}
        // bool f1=true,f2=true;
        // for(int i=0;i<n-1;i++){
        //     if(tops[i]!=tops[i+1])f1=false;
        //     if(bottoms[i]!=bottoms[i+1])f2=false;
        // }
        // if(f1) return c1;
        // else if(f2) return c2;

        return -1;
    }
};