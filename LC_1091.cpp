class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        queue<pair<pair<int,int>,int>> que;
        int curr_dist;
        int c_r, c_c;

        que.push({{0,0}, 1});

        while (que.empty() == false){
            c_r = que.front().first.first;
            c_c = que.front().first.second;
            curr_dist = que.front().second;
            que.pop();


            if(grid[c_r][c_c] == 1) continue;
            grid[c_r][c_c] = 1;

            if (c_r == size - 1 && c_c == size - 1) return curr_dist;

            if(c_r > 0 && grid[c_r - 1][c_c] != 1) que.push({{c_r - 1, c_c}, curr_dist + 1});
            if(c_r < size - 1 && grid[c_r + 1][c_c] != 1) que.push({{c_r + 1, c_c}, curr_dist + 1});

            if(c_c > 0 && grid[c_r][c_c - 1] != 1) que.push({{c_r, c_c - 1}, curr_dist + 1});
            if(c_c < size - 1 && grid[c_r][c_c + 1] != 1) que.push({{c_r, c_c + 1}, curr_dist + 1});

            if(c_r > 0 && c_c > 0 && grid[c_r -1][c_c - 1] != 1) que.push({{c_r - 1, c_c - 1}, curr_dist + 1});
            if(c_r > 0 && c_c < size - 1 && grid[c_r - 1][c_c + 1] != 1) que.push({{c_r - 1, c_c + 1}, curr_dist + 1});
            if(c_r < size - 1 && c_c > 0 && grid[c_r + 1][c_c - 1] != 1) que.push({{c_r + 1, c_c - 1}, curr_dist + 1});
            if(c_r < size - 1 && c_c < size - 1 && grid[c_r + 1][c_c + 1] != 1) que.push({{c_r + 1, c_c + 1}, curr_dist + 1});

        }

        return -1;

    }
};
