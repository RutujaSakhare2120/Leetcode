class Solution {
public:
//if all numbers are positive then this code is correct
    
    int subarraySum(vector<int>& nums, int k) {
        //prefix sum
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        
        int count=0;
        unordered_map<int ,int>s;
        for(int i=0;i<n;i++){
            
            if(nums[i]==k){
                count++;
               
            }
          
                int n1=nums[i]-k;
                if(s.find(n1)!=s.end()){
                    count+=s[n1];
                }
           
            
             s[nums[i]]++;

        }
         return count;
        
        
    }
};