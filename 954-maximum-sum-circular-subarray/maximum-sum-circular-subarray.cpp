
class Solution {
public:
    int maxKadane(vector<int>& nums){
        int n=nums.size();
        int currSum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<n;i++){
           currSum=max(nums[i] , nums[i]+currSum);
           maxSum=max(maxSum , currSum);
        }
        return maxSum;

     }
    int minKadane(vector<int>& nums){
    
     int n=nums.size();
        int currSum=nums[0];
        int minSum=nums[0];
        for(int i=1;i<n;i++){
           currSum=min(nums[i] , nums[i]+currSum);
           minSum=min(minSum , currSum);
        }
        return minSum;
     }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();

        int maxNormal=maxKadane(nums);

        if(maxNormal < 0) return maxNormal;
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }

        int minSum=minKadane(nums);
        int maxCircular=totalSum-minSum;


        return max(maxNormal , maxCircular);

    }
};