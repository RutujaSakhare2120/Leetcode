class Solution {
public:
   
   

    void dfs(vector<vector<char>>& grid , int row , int col){
        int n=grid.size();
         int m=grid[0].size();
         if(row<0 || row>=n || col<0 || col>=m ) return;
       if(grid[row][col]!='1') return ;
       grid[row][col]='2' ;
       dfs(grid , row+1 , col);
       dfs(grid , row-1 , col);
       dfs(grid , row , col+1);
       dfs(grid , row , col-1);

    }

   int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                result++;
                dfs(grid, i, j);
            }
        }
    }
    return result;
}
};