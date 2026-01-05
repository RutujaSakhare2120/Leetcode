class Solution {
public:
    vector<int>dp;
    bool helper(int idx, vector<int>& nums){
        if(idx>=nums.size()-1) return true;
        if(dp[idx]!=-1) return dp[idx];
        bool ans=false;
        for(int i=1;i<=nums[idx];i++){
            ans=ans|| helper(idx+i,nums);
            if(ans) break;

        }
        return dp[idx]=ans;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size() , -1);
       return helper(0,nums);

    }
};