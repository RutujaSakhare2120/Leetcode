class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        

       
        int count=0;
        while(!is_sorted(nums.begin(), nums.end())){
           count++;
           int minVal=INT_MAX;
           int idx=-1;
           int n=nums.size();
           for(int i=0;i<n-1;i++){
            int val=nums[i]+nums[i+1];
            if(minVal>val){
                minVal=val;
                idx=i;
            }
           }

           nums[idx]=minVal;
           nums.erase(nums.begin()+(idx+1));
           nums.resize(n-1);

        }
        return count;
        
    }
};