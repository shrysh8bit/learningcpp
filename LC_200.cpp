class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int,int>> que;
        set<pair<int, int>> visited;
        pair<int, int> a;
        int row, col;
        
        int islands = 0, m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                
                if (grid[i][j] == '0' || visited.find({i,j}) != visited.end()){
                    continue;
                }
                
                visited.insert({i,j});
                que.push({i,j});
                
                while (!que.empty()){
                    a = que.front();
                    row = a.first;
                    col = a.second;
                    
                    if (row + 1 < m && grid[row+1][col] == '1' && visited.find({row + 1,col}) == visited.end()){
                        que.push({row+1, col});
                        visited.insert({row+1, col});
                    }
                    
                    if (row - 1 >= 0 && grid[row-1][col] == '1' && visited.find({row - 1,col}) == visited.end()){
                        que.push({row-1, col});
                        visited.insert({row-1, col});
                    }
                    
                    if (col+1 < n && grid[row][col+1] == '1' && visited.find({row, col+1}) == visited.end()){
                        que.push({row, col+1});
                        visited.insert({row,col+1});
                    }
                    
                    
                    if (col-1 >= 0 && grid[row][col-1] == '1' && visited.find({row, col-1}) == visited.end()){
                        que.push({row, col-1});
                        visited.insert({row,col-1});
                    }
                    
                    // cout << que.front().first << " " <<que.front().second << " " << islands << endl;
                    que.pop();
                    
                    if (que.empty()){
                        islands++;
                    }
                }
            }
        }
        
        return islands;
    }
};