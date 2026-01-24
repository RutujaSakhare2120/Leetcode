class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int, int>m;
        for(int x: nums){
            int remain=k-x;
           
            if(m[remain]>0){
              count++;
              m[remain]--;
            }
            else m[x]++;
        }

        return count;
    }
};