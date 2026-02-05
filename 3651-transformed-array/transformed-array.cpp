class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
         vector<int> result(n);
        for(int i=0;i<n;i++){
         nums[i]%n;
         int newIdx=(i+nums[i])%n;
         if(newIdx<0) newIdx=newIdx+n;
         result[i]=nums[newIdx];
        }
        return result;
        
    }
};