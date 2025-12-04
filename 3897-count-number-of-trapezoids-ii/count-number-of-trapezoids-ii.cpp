class Solution {
public:
    using ll = long long;
    using ull = unsigned long long;

    // pack two 32-bit signed values into one 64-bit key (no collisions when values fit 32-bit)
    static ull pack32(ll a, ll b) {
        ull ua = (ull)( (unsigned int)(a & 0xffffffff) );
        ull ub = (ull)( (unsigned int)(b & 0xffffffff) );
        return (ua << 32) | ub;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        // slopeKey -> list of intercept C (dy*x - dx*y)
        unordered_map<ull, vector<ll>> slopeIntersect;
        // midpointKey -> list of slopeKey
        unordered_map<ull, vector<ull>> midPoint;

        int n = points.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ll x1 = points[i][0], y1 = points[i][1];
                ll x2 = points[j][0], y2 = points[j][1];

                ll dx = x2 - x1;
                ll dy = y2 - y1;

                // normalize slope (dy,dx)
                if (dx == 0) {
                    // vertical line: represent slope as (1,0)
                    dy = 1;
                    dx = 0;
                } else if (dy == 0) {
                    // horizontal line: represent slope as (0,1)
                    dy = 0;
                    dx = 1;
                } else {
                    ll g = std::gcd(std::llabs(dx), std::llabs(dy));
                    dx /= g;
                    dy /= g;
                    // make dx positive to have unique sign
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                }

                // slope packed as 32-bit pair
                ull slopeKey = pack32(dy, dx);

                // intercept constant: dy*x - dx*y  (integer, exact)
                ll C = dy * x1 - dx * y1;

                slopeIntersect[slopeKey].push_back(C);

                // midpoint (x1+x2, y1+y2) packed
                ll mx = x1 + x2;
                ll my = y1 + y2;
                ull midKey = pack32(mx, my);

                midPoint[midKey].push_back(slopeKey);
            }
        }

        long long ans = 0;

        // PART 1: count pairs of segments with same slope but different intercepts
        for (auto &p : slopeIntersect) {
            if (p.second.size() <= 1) continue;
            unordered_map<ll,int> cnt;
            for (ll C : p.second) cnt[C]++;
            long long pref = 0;
            for (auto &kv : cnt) {
                long long c = kv.second;
                ans += pref * c;
                pref += c;
            }
        }

        // PART 2: subtract pairs that share the same midpoint (duplicates)
        for (auto &p : midPoint) {
            if (p.second.size() <= 1) continue;
            unordered_map<ull,int> cnt;
            for (ull s : p.second) cnt[s]++;
            long long pref = 0;
            for (auto &kv : cnt) {
                long long c = kv.second;
                ans -= pref * c;
                pref += c;
            }
        }

        return (int)ans;
    }
};
