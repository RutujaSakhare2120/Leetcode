
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<double, double>> events;
        double totalArea = 0;

        // Create events
        for (auto &s : squares) {
            double y = s[1];
            double side = s[2];

            events.push_back({y, side});          // start
            events.push_back({y + side, -side});  // end

            totalArea += side * side;
        }

        // Sort events by y-coordinate
        sort(events.begin(), events.end());

        double target = totalArea / 2.0;
        double areaSoFar = 0;
        double activeWidth = 0;

        for (int i = 0; i + 1 < events.size(); i++) {
            double y = events[i].first;
            activeWidth += events[i].second;

            double nextY = events[i + 1].first;
            double height = nextY - y;

            if (height <= 0) continue;

            double areaGain = activeWidth * height;

            // Check if target is crossed in this segment
            if (areaSoFar + areaGain >= target) {
                double remaining = target - areaSoFar;
                return y + remaining / activeWidth;
            }

            areaSoFar += areaGain;
        }

        return 0.0; // fallback (won't happen)
    }
};
