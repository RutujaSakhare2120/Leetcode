class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            int evenCnt = 0, oddCnt = 0;

            for (int j = i; j < n; j++) {
                if (!seen.count(nums[j])) {
                    seen.insert(nums[j]);
                    if (nums[j] % 2 == 0)
                        evenCnt++;
                    else
                        oddCnt++;
                }

                if (evenCnt == oddCnt) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};
