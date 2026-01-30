class Solution {
public:
    const int INF = 1e9;        // for int
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>grid(26 ,vector<int>(26,INF) );
        for(int i=0;i<26;i++){
            grid[i][i]=0;
        }

        for(int i=0;i<original.size();i++){
            char src=original[i];
            char dest=changed[i];
            int a=src-'a';
            int b=dest-'a';
            grid[a][b]=min( grid[a][b] ,cost[i] );
        }

        //apply floyd warshall algorithm

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(grid[i][k] < INF && grid[k][j] < INF)
    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);

                }
            }
        }
       long long ans=0;
        for(int i=0;i<source.size();i++){
            char src=source[i];
            char dest=target[i];
            int a=src-'a';
            int b=dest-'a';
            if(grid[a][b]==INF) return -1;
            ans+= (long long)grid[a][b];
        }
        return ans;
    }
};