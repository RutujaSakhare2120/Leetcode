class Solution {
public:
//tabulation+space i=optimization
    vector<vector<int>>dp;
    
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize( 2, vector<int>(amount+1,INT_MAX));
         for(int i=0;i<=1;i++){
            dp[i][0]=0;
         }

         for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){

                if(j-coins[i-1]<0)  dp[1][j]=dp[0][j];
                else{
                long long take=1LL+dp[1][j-coins[i-1]];
                long long leave=dp[0][j];
                 dp[1][j]=min(take , leave);
                }
               
            }
             //copy past 1st row to oth row
             for(int j=1;j<=amount;j++){
                dp[0][j]=dp[1][j];
             }
         }
        if(dp[1][amount]==INT_MAX) return -1;
        return dp[1][amount];
    }
};