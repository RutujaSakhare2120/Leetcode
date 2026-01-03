class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
       vector<int>ans(n);

       int zeroCount=0;
       int product=1;
       for(int a:nums){
        if(a==0) zeroCount++;
        else product*=a;
       }

       for(int i=0;i<n;i++){
          if(zeroCount>0 && nums[i]!=0) ans[i]=0;
          else if(nums[i]==0 && zeroCount==1) ans[i]=product;
          else if(nums[i]==0 && zeroCount>1) ans[i]=0;
          else if(nums[i]!=0)ans[i]=product/nums[i];
       }
      return ans;
        
    }
};