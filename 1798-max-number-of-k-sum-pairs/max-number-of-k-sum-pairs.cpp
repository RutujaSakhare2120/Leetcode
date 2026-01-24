class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0;

        for (int x : nums) {
            int remain = k - x;

            if (m[remain] > 0) {
                count++;
                m[remain]--;
            } else {
                m[x]++;
            }
        }
        return count;
    }
};
