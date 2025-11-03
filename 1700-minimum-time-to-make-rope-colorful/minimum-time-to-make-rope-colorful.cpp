class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
          int total = 0;
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[i - 1]) {
                // Remove the smaller one
                total += min(neededTime[i], neededTime[i - 1]);
                // Keep the larger one for next comparison
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return total;
    }
};