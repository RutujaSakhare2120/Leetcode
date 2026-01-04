class Solution {
public:
    int helper(int n){
        if(n==0) return 0;
         vector<int>v;
       
       for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n / i)
               v.push_back(n/i);
        }
    }
        if(v.size()!=4) return 0;

       int sum=0;
       for(int a:v) sum+=a;
       return sum;

    }
    int sumFourDivisors(vector<int>& nums) {
    
        int n=nums.size();
       
        int ans=0;

        for(int i=0;i<n;i++){
          ans+=helper(nums[i]);
        }
        return ans;

    }
};