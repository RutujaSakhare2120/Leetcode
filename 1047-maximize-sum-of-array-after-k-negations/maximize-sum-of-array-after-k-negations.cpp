class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int , vector<int> , greater<int>>minHeap(nums.begin() , nums.end());
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        while(k--){
            int ele=minHeap.top();
            if(ele==0) break;
            
            minHeap.pop();
            sum-=ele;
            minHeap.push(-(ele));
            sum+=(-(ele));

        }
        return sum;
        
    }
};