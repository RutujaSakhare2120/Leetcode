class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;

        // STEP 1: build cost graph for characters
        vector<vector<long long>> dist(26, vector<long long>(26, INF));

        for(int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for(int i = 0; i < original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // STEP 2: Floyd-Warshall (minimum cost between all chars)
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    if(dist[i][k] + dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // STEP 3: calculate answer (your loop logic, corrected)
        long long ans = 0;
        for(int i = 0; i < source.size(); i++){
            if(source[i] == target[i]) continue;

            long long d = dist[source[i]-'a'][target[i]-'a'];
            if(d == INF) return -1;   // impossible

            ans += d;
        }

        return ans;
    }
};
