class Solution {
public:
    vector<vector<int>>dp;
   int LCS(string &s1 , string &s2 , int i , int j){
     if(i==s1.size() || j==s2.size()) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     if(s1[i]==s2[j]) return dp[i][j]=1+LCS(s1,s2,i+1,j+1);
     int leftSide=LCS(s1,s2,i+1,j);
     int rightSide=LCS(s1,s2,i,j+1);

     return dp[i][j] =max(leftSide , rightSide);


   }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int maxVal=max(n,m);
        int minVal=min(n,m);
         dp.resize(n, vector<int>(m, -1));
         int ans=maxVal+minVal-(2*LCS(word1 ,word2 ,0,0));
        return ans;
        
    }
};