class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m =grid.size(),n=grid[0].size();
        long long sum =0;
        for(auto &row :grid) for(auto &cell:row) sum +=cell;
        long long p=0;
        for(int i=0;i< m-1;i++) {
            for(int j=0;j<n;j++) {
                p+=grid[i][j];
            }
            if(p==sum-p) return true;
        }
        p=0;
        for(int j=0;j<n-1;j++) {
            for(int i=0;i<m;i++) {
                p+=grid[i][j];
            }
            if(p==sum-p) return true;
        }
        return false;
    }
};