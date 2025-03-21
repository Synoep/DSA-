class Solution {
public:
    vector<vector<int>> dp;
    
    bool poss1(vector<int>& v, int i, int t) 
    {
        if (t == 0) 
            return true;
        if(t<0)
            return false;
        if (i >= v.size()) 
            return false;
        if (dp[i][t] != -1) 
            return dp[i][t];
        
        
        return (dp[i][t] = (poss1(v, i + 1, t) || poss1(v, i + 1, t-v[i])));
    }
    
    bool poss(vector<int>&v,vector<vector<int>>& q,int k)
    {
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            vector<int>t;
            for(int j=0;j<k;j++)
            {
                if(q[j][0]<=i && q[j][1]>=i)
                    t.push_back(q[j][2]);
            }
            dp.clear();
            dp.resize(t.size(), vector<int>(1e4 + 10, -1));
            if(!poss1(t,0,v[i]))
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& v, vector<vector<int>>& q) 
    {
        int n=v.size(),m=q.size();
        int l=0,r=m;
        int ans=m+10;
        while(l<=r)
        {
            int mid=(r-l)/2+l;
            if(poss(v,q,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        // poss(v,q,2);
        if(ans<=m)
            return ans;
        return -1;
    }
};