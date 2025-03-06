
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq (n*n+1 , 0) ;
        for(auto & row : grid)
            for(auto & col : row)
                freq[col]++;
        
        vector<int> ans(2,0);
        for(int i = 1 ; i <= n*n ; i++)
            if (freq[i] == 2)
                ans[0] =i;
            else if ( freq[i] == 0)
                ans[1] = i ;
        
       return ans;
                
    }
};

