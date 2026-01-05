class Solution {
public:
   //recusion

   int helper(int n, vector<int>&dp){
     if(n==0) return 0;
    else  if(n==1 || n==2) return 1;
    if(dp[n]!=-1) return dp[n];
     return dp[n]=helper(n-1,dp)+helper(n-2,dp)+helper(n-3,dp);
    
   }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        int ans= helper(n,dp);
        return ans;
    }
};