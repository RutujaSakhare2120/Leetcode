class Solution {
public:
    int helper(vector<int>& nums,int idx , int sum ,int target)
    {    if(idx==nums.size()){
            if(sum==target) return 1;
            else return 0;
          }
         int add=helper(nums, idx+1, sum+nums[idx] , target);
         int sub=helper(nums, idx+1, sum-nums[idx] , target);    
         return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, 0 , 0 ,target);
    }
};