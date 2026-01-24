class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin() ,  nums.end());
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<right){
         int val=nums[left]+nums[right];
         ans=max(ans , val);
         left++;
         right--;
        }
        return ans;
    }
};