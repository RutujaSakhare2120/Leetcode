class Solution {
public:
    int sum(vector<int>& nums , int i , int j){
        int count=0;
        for(int k=i;k<=j;k++){
            count+=nums[k];
        }
        return count;
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                
                int sumL=sum(nums , 0 , i-1);
                int sumR=sum(nums , i+1 , n-1);
                if(sumL==sumR) result+=2;
                if(abs(sumL-sumR)==1) result+=1;
            }
        }
        return result;
        
    }
};