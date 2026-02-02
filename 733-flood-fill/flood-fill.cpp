class Solution {
public:
 void dfs(vector<vector<int>>& image, int currRow, int currCol, int oldColor , int color){
 int n=image.size();
 int m=image[0].size();
 if(currRow<0 || currRow>=n || currCol<0 || currCol>=m ) return;

 if(image[currRow][currCol] !=oldColor) return;

 image[currRow][currCol]=color;
 dfs(image , currRow+1 , currCol , oldColor ,color );//down
 dfs(image , currRow-1 , currCol , oldColor ,color );//up
 dfs(image , currRow , currCol+1 , oldColor ,color );//right
 dfs(image , currRow , currCol-1 , oldColor ,color );//left

return;

 }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image , sr , sc , image[sr][sc] , color);
        return image;
        
    }
};