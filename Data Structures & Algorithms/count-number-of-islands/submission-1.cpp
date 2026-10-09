class Solution {
public:
    void bfs(queue<pair<int, int>> &q, vector<vector<char>>& grid){
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            grid[r][c] = '0';
            int dr[] = {-1, 0, 0, 1};
            int dc[] = {0, 1, -1, 0};
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                while(nr>=0 && nr < grid.size()
                && nc>=0 && nc < grid[0].size() &&
                grid[nr][nc] == '1'){
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int islands = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == '1'){
                    q.push({i, j});
                    bfs(q, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};