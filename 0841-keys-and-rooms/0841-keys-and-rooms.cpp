class Solution {
    void dfs(vector<vector<int>>& rooms, vector<int>& visited, int idx){
        visited[idx] = 1;
        for(int i : rooms[idx]){
            if(!visited[i]){
                // visited[i] = 1;
                dfs(rooms, visited, i);
                // visited[i] = 0;
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        // visited[0] = 1;
        dfs(rooms, visited, 0);

        for(int i : visited){
            if(!i){
                return false;
            }
        }
        return true;
    }
};