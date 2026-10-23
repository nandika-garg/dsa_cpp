class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m=image.size();
        int n= image[0].size();
        int x=image[sr][sc];
        image[sr][sc]=color;
        if(sr+1<m && image[sr+1][sc]==x) floodFill(image, sr+1, sc, color);
        if(sr-1>=0 && image[sr-1][sc]==x) floodFill(image, sr-1, sc, color);
        if(sc+1<n && image[sr][sc+1]==x) floodFill(image, sr, sc+1, color);
        if(sc-1>=0 && image[sr][sc-1]==x) floodFill(image, sr, sc-1, color);
    
        return image;
    }
};