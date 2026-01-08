class Solution {
public:
     int totalSum=0;
      vector<vector<int>>dp;
     int target=0;
    

     bool helper(vector<int>& nums , int idx , int currSum , int n){
          if(currSum==target) return true;
        if(idx==n) return false;
         if(dp[idx][currSum]!=-1) return dp[idx][currSum];
        
         if(currSum+nums[idx]>target) return dp[idx][currSum]=helper(nums,idx+1,currSum,n);
         int take=helper(nums,idx+1,nums[idx]+currSum,n);
         int leave=helper(nums,idx+1,currSum,n);
         return dp[idx][currSum]=take || leave;
     }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
     
       for(int a:nums) totalSum+=a;
       if(totalSum%2!=0) return false;//if sum is odd it is impossible to divide it into 2 parts
       target=totalSum/2;
       
        dp.resize(n,vector<int>(target+1,-1));
       return  helper(nums,0,0,n);
        
    }
};