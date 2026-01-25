class Solution {
public:
    long long  reverseD(int n){
        long long  ans=0;
        while(n>0){
            int last=n%10;
            ans=10*ans+last;
            n/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
         const int MOD=1e9+7;
        int n=nums.size();
      
       unordered_map<long long , long long >m;
        for(int i=0;i<n;i++){
             long long  revNo=0;
            if(nums[i]>=0 && nums[i]<=9) revNo=(nums[i]);
            else{
                 revNo=reverseD(nums[i]);
               
            }
             nums[i]=(nums[i]-revNo);

             m[nums[i]]++;
        }

       long long count = 0;
        for (auto it : m) {
            long long a = it.second;
            count = (count + (a * (a - 1) / 2) % MOD) % MOD;
        }

        return count;
       
    }
};