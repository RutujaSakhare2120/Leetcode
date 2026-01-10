class Solution {
public:
//tabulation
    vector<vector<int>>dp;
    
    int helper(vector<int>& coins, int amount , int idx){
      
        if(idx<0) {
              if(amount==0) return 0;
              else  return INT_MAX;//no valid ans
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        if(amount-coins[idx]<0) return dp[idx][amount]=helper(coins,amount,idx-1);//leave
        long long take=1LL+helper(coins,amount-coins[idx],idx);
        long long leave=helper(coins,amount,idx-1);
        return dp[idx][amount]=min(take , leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize( n, vector<int>(amount+1,-1));
        int ans= helper(coins,amount,n-1);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};