class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        // Build directed graph with extra reversed edges
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            // original edge cost
            adj[u].push_back({v, w});

            // reversed edge (cost = 2 * original)
            adj[v].push_back({u, 2 * w});
        }

        // Dijkstra
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[0] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &pr : adj[u]) {
                int v = pr.first, cost = pr.second;
                if(dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n-1] == INF ? -1 : dist[n-1];
    }
};
