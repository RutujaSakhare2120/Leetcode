class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isSorted(nums)) {
            int minSum = nums[0] + nums[1];
            int idx = 0;

            // find leftmost adjacent pair with minimum sum
            for (int i = 1; i < nums.size() - 1; i++) {
                int currSum = nums[i] + nums[i + 1];
                if (currSum < minSum) {
                    minSum = currSum;
                    idx = i;
                }
            }

            // merge the pair
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }

        return operations;
    }
};
