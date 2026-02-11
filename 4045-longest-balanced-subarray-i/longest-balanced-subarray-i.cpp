class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxLength=0;
        for(int i=0;i<n-1;i++){
            int evenCount=0;
            int oddCount=0;
            unordered_set<int>even;
            unordered_set<int>odd;

            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    if(even.find(nums[j])==even.end()){
                        even.insert(nums[j]);
                         evenCount++;
                    }
                   
                }
                else{
                     if(odd.find(nums[j])==odd.end()){
                        odd.insert(nums[j]);
                        oddCount++;
                    }
                    
                }


                if(evenCount==oddCount){
                    maxLength=max(maxLength , (j-i+1));
                }


            }
        }
        return maxLength;

        
    }
};