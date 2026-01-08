class Solution {
public:
   unordered_map< int,vector<int> >dp;
    int total=0;
    int helper(vector<int>& nums,int idx , int sum ,int target)
    {    if(idx==nums.size()){
            if(sum==target) return 1;
            else return 0;
          }
          if( dp[sum][idx]!=-1) return dp[sum][idx];
         int add=helper(nums, idx+1, sum+nums[idx] , target);
         int sub=helper(nums, idx+1, sum-nums[idx] , target);    
         return   dp[sum][idx]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        for(int a:nums) total+=a;
        for(int i=-total;i<=total;i++){
            vector<int>v(nums.size(),-1);
            dp[i]=v;
        }
        return helper(nums, 0 , 0 ,target);
    }
};