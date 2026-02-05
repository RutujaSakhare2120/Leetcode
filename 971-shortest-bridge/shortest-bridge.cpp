class Solution {
public:
    int m, n;
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isSafe(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }

    void dfs(vector<vector<int>>& grid ,int i, int j ,  set<pair<int , int>>&visitedCell){

        if(!(isSafe(i ,j)) || grid[i][j]==0 || visitedCell.find({i,j})!=visitedCell.end() ) return;

         visitedCell.insert({i,j});
         for(int d=0;d<4;d++){
            int x=i+dir[d][0];
            int y=j+dir[d][1];

            dfs(grid , x ,y,visitedCell);
         }

    }

    int bfs(vector<vector<int>>& grid ,set<pair<int , int>>&visitedCell){

        queue<pair<int ,int>>q;
        for(auto &it:visitedCell){
            q.push(it);}
            int level=0;
            while(!q.empty()){
                int l=q.size();
                while(l--){
                    auto p=q.front();
                    q.pop();
                    int x=p.first;
                    int y=p.second;

                      for(int d=0;d<4;d++){
                            int x1=x+dir[d][0];
                            int y1=y+dir[d][1];

                            if(isSafe(x1 ,y1) && visitedCell.find({x1,y1})==visitedCell.end()) {
                                if(grid[x1][y1]==1) return level;
                                visitedCell.insert({x1,y1});
                                q.push({x1,y1});
                            }
                            

           
                      }

                   
                }
                 level++;
               
        }


      return level;
    }
    int shortestBridge(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        set<pair<int , int>>visitedCell;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]==1){
                dfs(grid ,i,j,visitedCell);
                return bfs(grid ,visitedCell);
              }
            }
        }
        return -1;
    }
};