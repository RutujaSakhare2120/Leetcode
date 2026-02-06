class Solution {
public:

    int minRemoval(vector<int>& nums, int k) {
       int n=nums.size();
       sort(nums.begin() ,  nums.end());
       int len=INT_MAX;
       int i=0;
       int j=0;
       int maxLen=INT_MIN;
       while(j<n){
        while(i<n &&nums[j]> 1LL*nums[i]*k) i++;
       
        maxLen=max(j-i+1,maxLen);
        j++;
       }
       
       return n-maxLen;
    }
};