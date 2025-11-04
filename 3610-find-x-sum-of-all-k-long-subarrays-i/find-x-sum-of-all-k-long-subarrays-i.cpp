#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P; // {freq, value}

    int findTopXSum(unordered_map<int, int>& mp, int x) {
        // Custom comparator for min-heap
        auto cmp = [](const P& a, const P& b) {
            if (a.first == b.first)
                return a.second > b.second; // smaller value out first
            return a.first > b.first; // smaller freq out first
        };

        priority_queue<P, vector<P>, decltype(cmp)> pq(cmp);

        for (auto& it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > x) pq.pop(); // maintain top x
        }

        int sum = 0;
        while (!pq.empty()) {
            auto [freq, val] = pq.top();
            pq.pop();
            sum += freq * val; // ✅ Correct formula
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> result;
        int i = 0, j = 0;

        while (j < n) {
            mp[nums[j]]++;

            if (j - i + 1 == k) {
                result.push_back(findTopXSum(mp, x));

                // Slide window
                if (--mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};
