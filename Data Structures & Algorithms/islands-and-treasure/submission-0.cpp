class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid){
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()){
                    continue;
                }
                if(grid[nr][nc] == INT_MAX){
                    grid[nr][nc] = 1 + grid[r][c];
                    q.push({nr, nc});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            } 
        }
        bfs(q, grid);

    }

};
