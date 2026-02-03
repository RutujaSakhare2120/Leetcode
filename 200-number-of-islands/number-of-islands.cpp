class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();

                        int r = p.first;
                        int c = p.second;

                        // up
                        if (r - 1 >= 0 && grid[r-1][c] == '1') {
                            q.push({r-1, c});
                            grid[r-1][c] = '0';
                        }
                        // down
                        if (r + 1 < n && grid[r+1][c] == '1') {
                            q.push({r+1, c});
                            grid[r+1][c] = '0';
                        }
                        // left
                        if (c - 1 >= 0 && grid[r][c-1] == '1') {
                            q.push({r, c-1});
                            grid[r][c-1] = '0';
                        }
                        // right
                        if (c + 1 < m && grid[r][c+1] == '1') {
                            q.push({r, c+1});
                            grid[r][c+1] = '0';
                        }
                    }
                }
            }
        }
        return result;
    }
};
