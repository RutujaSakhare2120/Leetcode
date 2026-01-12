class Solution {
public:
   //dp
    vector<vector<int>>dp;
    int solve(string &word1, string &word2,int i, int j){
        if(i<0) return j+1;
        if(j<0) return i+1;  
        if(dp[i][j]!=-1) return dp[i][j]; 
        if(word1[i]==word2[j]) return  dp[i][j]=solve(word1,  word2,i-1,j-1 );
        else{
            int add=1+solve(word1,  word2,i-1,j);
            int del=1+solve(word1,  word2,i,j-1 );
            int replace=1+solve(word1,  word2,i-1,j-1 );
            return dp[i][j]=min(add,min(del,replace));
        }

    }
    int minDistance(string word1, string word2) {
       dp.resize(word1.size(), vector<int>(word2.size(),-1));
        return solve( word1,  word2 , word1.size()-1 , word2.size()-1);
        
    }
};