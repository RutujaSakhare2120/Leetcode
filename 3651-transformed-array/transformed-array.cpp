class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
         vector<int> result(n);
        for(int i=0;i<n;i++){
            int a=nums[i];
            if(a==0){
             result[i]=nums[i];
            }
            else if(a>0){
               int j=i;
               for(int k=0;k<a;k++){
                 j++;
                 if(j==n){
                    j=0;
                 }
               }
               result[i]=nums[j];
            }
            else{
                a=-1*a;
                int j=i;
               for(int k=0;k<a;k++){
                 j--;
                 if(j<0){
                    j=n-1;
                 }
               }
               result[i]=nums[j];
            }

            
        }
        return result;
        
    }
};