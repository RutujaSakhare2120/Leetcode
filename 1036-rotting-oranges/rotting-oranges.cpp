class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int ,int>>q;
        int f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1) f++;
               else if(grid[i][j]==2) q.push({i,j});
            }
        }
        int min=0;
        q.push({-1,-1});

        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int r=curr.first;
            int c=curr.second;
            if(r==-1 && c==-1){
                min++;
                if(!q.empty()) {
                  q.push({-1,-1});
                 
                }
                else break;
            }

            else{
                for(int d=0;d<4;d++){
                int nr=r+dir[d][0];
                int nc=c+dir[d][1];

                if(nr<0 ||nr>=n || nc<0 || nc>=m) continue;
                if(grid[nr][nc]==2 || grid[nr][nc]==0) continue;
                grid[nr][nc]=2;
                f--;
                q.push({nr , nc});

              }
            }
        }
       
        return (f==0)? min-1 :-1;
        
    }
};