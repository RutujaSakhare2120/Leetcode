class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int r1min1=INT_MAX;
        int r1min2=INT_MAX;
        int r2min1=INT_MAX;
        int r2min2=INT_MAX;
        for(int x:nums){
         sum+=x;
         if(x%3==1){
            if(x<r1min1){
                r1min2=r1min1;
                r1min1=x;
            }
            else if(x<r1min2){
                r1min2=x;
            }

         }
         else if(x%3==2){
             if(x<r2min1){
                r2min2=r2min1;
                r2min1=x;
            }
            else if(x<r2min2){
                r2min2=x;
            }

         }

        }
         int remove=INT_MAX;
        if(sum%3==0) return sum;
        
        else if(sum%3==1){
            if(r1min1!=INT_MAX) remove=min(remove , r1min1);
            if(r2min2!=INT_MAX) remove=min(remove , r2min1+r2min2);

        }
        else{//sum%3==2
            if(r2min1!=INT_MAX) remove=min(remove , r2min1);
            if(r1min2!=INT_MAX) remove=min(remove , r1min1+r1min2);
        }

        return sum-remove;

    }
};