class Solution {
public:
    int gcd(int a , int b){
        if(a<b){
            int ans=1;
            for(int i=2;i<=a;i++){
                if(a%i==0 && b%i==0) ans=i;
            }
            return ans;
            
        }
        else{
              int ans=1;
            for(int i=2;i<=b;i++){
                if(a%i==0 && b%i==0) ans=i;
            }
            return ans;
            
                
        }

        return 1;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) count++;
        }
        if(count>0){
          return n-count;
        }
        
        int operation=INT_MAX;
        for(int i=0;i<n-1;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=gcd(g , nums[j]);
                if(g==1) operation=min(operation , j-i);
            }
        }


        if(operation==INT_MAX) return -1;
        return (n-1)+operation;
    }
};