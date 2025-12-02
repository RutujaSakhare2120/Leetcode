class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long combi(long long m) {
        return ((m * (m - 1) / 2) % MOD + MOD) % MOD; // safe modulo
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> mp;
        for(auto &p: points) {
            mp[p[1]]++;
        }

        vector<long long> v;
        for(auto &p: mp) {
            if(p.second >= 2) {
                v.push_back(combi(p.second));
            }
        }

        if(v.size() < 2) return 0;

        long long ans = 0;
        long long prefix = 0;
        for(long long x: v) {
            ans = (ans + (x * prefix) % MOD) % MOD;  // multiply under modulo
            prefix = (prefix + x) % MOD;             // prefix under modulo
        }

        return (int)ans;
    }
};
