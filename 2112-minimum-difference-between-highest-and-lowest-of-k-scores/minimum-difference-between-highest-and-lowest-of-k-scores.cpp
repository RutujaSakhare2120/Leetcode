class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin() , nums.end());
        if(k==1) return 0;
        int i=0;
        int j=k-1;
        int ans=INT_MAX;
        while(j<n){

          int a=nums[j]-nums[i];
          ans=min(ans , a);
          i++;
          j++;

          
        }

        return ans;
    }
};