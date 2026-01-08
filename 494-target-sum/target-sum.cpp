class Solution {
public:
    vector<vector<int>>dp;
    int total=0;
    int helper(vector<int>& nums,int idx , int sum ,int target)
    {    if(idx==nums.size()){
            if(sum==target) return 1;
            else return 0;
          }
          if( dp[idx][sum+total]!=-1) return dp[idx][sum+total];
         int add=helper(nums, idx+1, sum+nums[idx] , target);
         int sub=helper(nums, idx+1, sum-nums[idx] , target);    
         return  dp[idx][sum+total]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int a:nums) total+=a;
        dp.resize(n,vector<int>(2*total+1,-1));
        return helper(nums, 0 , 0 ,target);
    }
};