class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        vector<vector<int>> helper(n+1 , vector<int>((n+1),0));
        vector<vector<int>> ans( n, vector<int>((n) , 0));

        for(auto &p:queries){
            int r1=p[0];
            int c1=p[1];
            int r2=p[2];
            int c2=p[3];


            helper[r1][c1] +=1;
            helper[r1][c2+1] -=1;//right
            helper[r2+1][c1] -=1;//dowm
            helper[r2+1][c2+1] +=1;//right down (+ because 2 times - hua tha)


        }

        //row wise prefix
        for(int i=0;i<=n;i++){
            for(int j=1;j<=n;j++){
                helper[i][j]+=helper[i][j-1];
            }

        }
        
        //column wise prefix sum
         for(int j=0;j<=n;j++){
            for(int i=1;i<=n;i++){
                helper[i][j]+=helper[i-1][j];
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=helper[i][j];
            }
        }

      
        return ans;
    }
};