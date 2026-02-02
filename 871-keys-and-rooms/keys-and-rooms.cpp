class Solution {
public: // using DFS
    unordered_set<int> visited;

    void helper(vector<vector<int>>& rooms, int curr) {
        visited.insert(curr);   // ✅ mark first

        for (int neighbour : rooms[curr]) {
            if (!visited.count(neighbour)) {
                helper(rooms, neighbour);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        helper(rooms, 0);
        return visited.size() == rooms.size();
    }
};
