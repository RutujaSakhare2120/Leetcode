class Solution {
public://using BFS
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_set<int>visited;
        queue<int>q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto neighbour:rooms[curr]){
                if(!visited.count(neighbour)){
                     visited.insert(neighbour);
                     q.push(neighbour);
                }
            }
        }
        return visited.size()==rooms.size();
    }
};