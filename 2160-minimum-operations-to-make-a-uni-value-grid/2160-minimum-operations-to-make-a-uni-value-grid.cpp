class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        int even=0,odd=0, total=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                 v.push_back(grid[i][j]);
                 total++;
                 if(grid[i][j]%2==0) even++;
                 else odd++;
            }
        }
        sort(v.begin(),v.end());
         int mid=v[v.size()/2];
         int count=0;
         for (auto a:v) {
            if ((a-mid)%x!=0) return -1;
        }
         for(auto a:v){
            count+=abs(a-mid)/x;
         }
         return count;

    }
};