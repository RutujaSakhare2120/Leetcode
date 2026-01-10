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
    int minInsertions(string s) {
        string s1=s;
        reverse(s.begin() , s.end());
         dp.resize(s1.size() , vector<int>(s.size() , -1));
        return s.size()-LCS(s1 ,s ,0,0);
    }
};