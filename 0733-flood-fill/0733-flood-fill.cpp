class Solution {
public:
    void dfs(vector<vector<int>> &image,int sr,int sc,int color,int c){
          int n=image.size(),m=image[0].size();
          if(sr<0||sc<0||sr>=n||sc>=m||image[sr][sc]!=c||image[sr][sc]==color) return;
          image[sr][sc]=color;
          dfs(image,sr+1,sc,color,c);
          dfs(image,sr-1,sc,color,c);
          dfs(image,sr,sc+1,color,c);
          dfs(image,sr,sc-1,color,c);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c=image[sr][sc];
        dfs(image,sr,sc,color,c);
        return image;
    }
};