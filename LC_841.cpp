class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<int> visited (size,0);
        
        queue<int> que;
        que.push(0);
        
        int curr_room;
        
        while (!que.empty()){
            curr_room = que.front();
            visited[curr_room] = 1;
            que.pop();
            
            for (int i : rooms[curr_room]){
                if (visited[i] == 0){
                    que.push(i);
                }
            }
        }
        
        for (int i : visited){
            if (i == 0) return false;
        }
        
        return true;
        
    }
};