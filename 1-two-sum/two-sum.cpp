class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int , int>m;

        for(int i=0;i<n;i++){
            int remain=target-nums[i];
            if(m.find(remain)!=m.end()){
                return {m[remain] , i};
            }
            else m[nums[i]]=i;
        }
        return {};
    }
};