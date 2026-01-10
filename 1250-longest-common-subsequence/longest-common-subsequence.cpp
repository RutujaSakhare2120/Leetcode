class Solution {
public:
    vector<vector<int>>dp;
    //tabulation +space optimization
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(2 , vector<int>((text2.size()+1) , 0));

        for(int i=1;i<=text1.size();i++){
           for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-1]) dp[1][j]=1+dp[0][j-1];
            else dp[1][j]=max(dp[0][j] , dp[1][j-1]);
           }

            for(int j=1;j<=text2.size();j++){
                dp[0][j]=dp[1][j];
             }
        }

        return dp[1][text2.size()];
    }
};