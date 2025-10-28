class Solution {
public:
    // bool isValidR(int curr, vector<int> nums) {
    //     int n = nums.size();
    //     if (curr < 0 || curr >= n) {
    //         for (int i = 0; i < n; i++)
    //             if (nums[i] != 0) return false;
    //         return true;
    //     }

    //     curr++;
    //     if (curr >= n) {
    //         for (int i = 0; i < n; i++)
    //             if (nums[i] != 0) return false;
    //         return true;
    //     }

    //     if (nums[curr] == 0)
    //         return isValidR(curr, nums);
    //     else {
    //         nums[curr]--;
    //         return isValidL(curr, nums);
    //     }
    // }

    // bool isValidL(int curr, vector<int> nums) {
    //     int n = nums.size();
    //     if (curr < 0 || curr >= n) {
    //         for (int i = 0; i < n; i++)
    //             if (nums[i] != 0) return false;
    //         return true;
    //     }

    //     curr--;
    //     if (curr < 0) {
    //         for (int i = 0; i < n; i++)
    //             if (nums[i] != 0) return false;
    //         return true;
    //     }

    //     if (nums[curr] == 0)
    //         return isValidL(curr, nums);
    //     else {
    //         nums[curr]--;
    //         return isValidR(curr, nums);
    //     }
    // }

    bool check(vector<int>& nums , int i , int count , int dir){  int idx=i;
        vector<int>temp=nums;
        while(idx>=0 && idx<nums.size() && count>0){
            if(temp[idx]>0){
              temp[idx]--;
              dir*=-1;
               if(temp[idx]==0){
                count--;

            }
              }
              
            idx+=dir;
        }
        return count ==0;
    }

    int countValidSelections(vector<int>& nums) {
        // int n = nums.size();
        // int count = 0;
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == 0) {
        //         if (isValidR(i, nums)) count++;
        //         if (isValidL(i, nums)) count++;
        //     }
        // }
        // return count;

        int n=nums.size();
        int result=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) count++;
        }
        
        for(int i=0;i<n;i++){
           if(nums[i]==0){
             if(check(nums , i , count , -1)) result++;
            if(check(nums , i , count , +1)) result++;
           }


        }

      return result;
    }
};
