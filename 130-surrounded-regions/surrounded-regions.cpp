class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;

        // Borders
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][m-1] == 'O') q.push({i,m-1});
        }

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') q.push({0,j});
            if(board[n-1][j] == 'O') q.push({n-1,j});
        }

        // BFS
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            if(board[r][c] != 'O') continue;
            board[r][c] = '1';   // mark safe

            for(int d = 0; d < 4; d++){
                int nr = r + dir[d][0];
                int nc = c + dir[d][1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                if(board[nr][nc] == 'O'){
                    q.push({nr, nc});
                }
            }
        }

        // Final conversion
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};
