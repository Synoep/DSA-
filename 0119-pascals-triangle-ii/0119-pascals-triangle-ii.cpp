class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> v(r+1,0);
        v[0]=1;
        for(int i=1;i<r+1;i++)
          for(int j=i;j>=1;j--)
                v[j]+=v[j-1];
        return v;
    }
};