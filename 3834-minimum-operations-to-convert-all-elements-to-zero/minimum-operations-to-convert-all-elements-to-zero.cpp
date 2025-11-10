#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        st.push(0);  // sentinel for easier handling
        int ans = 0;

        for (int num : nums) {
            // Pop all larger elements
            while (!st.empty() && st.top() > num)
                st.pop();

            // If current num is greater than top → new operation
            if (st.empty() || st.top() < num) {
                ans++;
                st.push(num);
            }
            // If equal, do nothing (already handled)
        }

        return ans;
    }
};
