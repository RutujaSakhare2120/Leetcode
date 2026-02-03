class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n-1 && nums[i]<nums[i+1]) i++;
        if(i==0) return false;
        int a=i;
        while(i<n-1 && nums[i]>nums[i+1])i++;
        if(i==a) return false;
        int b=i;
        while(i<n-1 && nums[i]<nums[i+1]) i++;
        if(i==b) return false;
        return i+1==n;
        
    }
};