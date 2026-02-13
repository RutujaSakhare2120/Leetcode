class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int remain=target-nums[i];
            if(mp.find(remain)==mp.end()) mp.insert({nums[i] , i});
            else {
                ans.push_back(i);
                ans.push_back(mp[remain]);
            }
        }
        return ans;
    }
};