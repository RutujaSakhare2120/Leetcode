class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a=nums[0];
        sort(nums.begin()+1  , nums.end());
        int sum=0;
        return sum=a+nums[1]+nums[2];

        
    }
};