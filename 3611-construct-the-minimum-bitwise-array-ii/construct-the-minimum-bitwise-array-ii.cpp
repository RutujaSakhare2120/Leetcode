class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
         vector<int>ans;
         int n=nums.size();
         for(int i=0;i<n;i++){

            if(nums[i]==2){
             ans.push_back(-1);
             continue;
            }
            for(int j=0;j<32;j++){
                if((nums[i]&(1<<j)) >0){//set bit for nums[i] number at jth position

                 continue;

                }

                int x=nums[i]^(1<<(j-1));
                 ans.push_back(x);
                 break;
            }
         }
         return ans;
    }

};