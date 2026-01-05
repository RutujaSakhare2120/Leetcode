class Solution {
public:
//tabulation+space optimization
    int tribonacci(int n) {
        vector<int>dp(4);
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[3]=dp[1]+dp[2]+dp[0];
            dp[0]=dp[1];
            dp[1]=dp[2];
            dp[2]=dp[3];
        }
       return  dp[3];
    }
};