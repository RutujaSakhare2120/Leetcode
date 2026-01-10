class Solution {
public:
//recursion+memorization
   vector<vector<int>>dp;
   int helper(string &s1 , string &s2 , int i , int j){
     if(i==s1.size() || j==s2.size()) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(s1[i]==s2[j]) return dp[i][j]=1+helper(s1,s2,i+1,j+1);
     int leftSide=helper(s1,s2,i+1,j);
     int rightSide=helper(s1,s2,i,j+1);

     return dp[i][j] =max(leftSide , rightSide);


   }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size() , vector<int>(text2.size() , -1));
        return helper(text1,text2,0,0);
        
    }
};