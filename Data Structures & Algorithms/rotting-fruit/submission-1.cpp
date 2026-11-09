class Solution {
public:
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, int& time){
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while(!q.empty()){
            int size = q.size();
            bool rotten = false;
            for(int i = 0; i < size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) continue;

                    if(grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        rotten = true;
                    }
                }
            }
            if(rotten) time += 1;
        }
        return time;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int time = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        bfs(q, grid, time);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
