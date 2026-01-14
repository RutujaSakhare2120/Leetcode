class Solution {
public:
    struct Event {
        double y, x1, x2;
        int type; // +1 add, -1 remove
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        vector<double> xs;

        for (auto &s : squares) {
            double x = s[0], y = s[1], len = s[2];
            events.push_back({y, x, x + len, +1});
            events.push_back({y + len, x, x + len, -1});
            xs.push_back(x);
            xs.push_back(x + len);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end());

        int m = xs.size();
        vector<int> count(m * 4, 0);
        vector<double> length(m * 4, 0);

        function<void(int,int,int,int,int,int)> update =
        [&](int node, int l, int r, int ql, int qr, int val) {
            if (ql >= r || qr <= l) return;
            if (ql <= l && r <= qr) {
                count[node] += val;
            } else {
                int mid = (l + r) / 2;
                update(node*2, l, mid, ql, qr, val);
                update(node*2+1, mid, r, ql, qr, val);
            }

            if (count[node] > 0) {
                length[node] = xs[r] - xs[l];
            } else if (r - l == 1) {
                length[node] = 0;
            } else {
                length[node] = length[node*2] + length[node*2+1];
            }
        };

        // First pass: total area
        double total = 0, prevY = events[0].y;
        for (auto &e : events) {
            total += length[1] * (e.y - prevY);
            int l = lower_bound(xs.begin(), xs.end(), e.x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), e.x2) - xs.begin();
            update(1, 0, m - 1, l, r, e.type);
            prevY = e.y;
        }

        double half = total / 2.0;

        // Reset
        fill(count.begin(), count.end(), 0);
        fill(length.begin(), length.end(), 0);

        // Second pass: find split Y
        double curr = 0;
        prevY = events[0].y;

        for (auto &e : events) {
            double area = length[1] * (e.y - prevY);
            if (curr + area >= half) {
                return prevY + (half - curr) / length[1];
            }
            curr += area;

            int l = lower_bound(xs.begin(), xs.end(), e.x1) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), e.x2) - xs.begin();
            update(1, 0, m - 1, l, r, e.type);
            prevY = e.y;
        }

        return prevY;
    }
};
