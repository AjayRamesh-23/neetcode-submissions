class Solution {
public:
    void bfs(vector<vector<char>> &grid, set<pair<int, int>> &visited, queue<pair<int, int>> &q){
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr < grid.size() &&
                nc >=0 && nc < grid[0].size() &&
                grid[nr][nc] == '1' &&
                !visited.contains({nr, nc})){
                    q.push({nr, nc});
                    visited.insert({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int islands = 0;
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == '1' && !visited.contains({i,j})){
                    visited.insert({i, j});
                    q.push({i,j});
                    bfs(grid, visited, q);
                    islands++;
                }
            }
        }
        return islands; 
    }
};
