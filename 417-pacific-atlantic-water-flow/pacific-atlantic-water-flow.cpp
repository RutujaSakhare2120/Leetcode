class Solution {
public:
    vector<vector<int>>dir={{1,0} ,{-1,0},{0,1} ,{0,-1}};
    int n;
    int m;
    vector<vector<int>>h;
    vector<vector<bool>>  bfs( queue<pair<int , int>>&q){
        vector<vector<bool>> visited(n , vector<bool>(m,false));
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int i=curr.first;
            int j=curr.second;
            if (visited[i][j]) continue;
            visited[i][j]=true;
            for(int d=0;d<4;d++){
                int newRow=i+dir[d][0];
                int newCol=j+dir[d][1];

                if(newRow<0 || newRow>=n || newCol<0 || newCol>=m) continue;
                if(visited[newRow][newCol]) continue;
                if(h[newRow][newCol]< h[i][j]) continue;
                q.push({newRow , newCol});
            }
           
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         n=heights.size();
         m=heights[0].size();
        h=heights;
        queue<pair<int , int>> pacificbfs;
        queue<pair<int , int>> atlanticbfs;

        vector<vector<int>>result;

        for(int i=0;i<n;i++){
            pacificbfs.push({i ,0});
            atlanticbfs.push({i ,m-1});
        }

        for(int i=0;i<m;i++){
            pacificbfs.push({0 ,i});
        }

        for(int i=0;i<m;i++){
            atlanticbfs.push({n-1 ,i});
        }

        vector<vector<bool>> pacific=bfs(pacificbfs);
        vector<vector<bool>> atlantic=bfs(atlanticbfs);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(pacific[i][j] && atlantic[i][j]) result.push_back({i ,j});
            }
        }
        return result;
    }
};