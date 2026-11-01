class Solution {
public:
    set<vector<int>> bfs(vector<vector<int>>& heights, vector<vector<int>>& visited, queue<vector<int>> q){
        int rows = heights.size();
        int cols = heights[0].size();
        set<vector<int>> nodes;

        while(!q.empty()){
            int r = q.front()[0];
            int c = q.front()[1];
            q.pop();
            nodes.insert({r, c});

            int dr[] = {0, 0, 1, -1};
            int dc[] = {1, -1, 0, 0};

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols || visited[nr][nc]){
                    continue;
                }
                if(heights[nr][nc] >= heights[r][c]){
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return nodes;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();
        
        set<vector<int>> pacificSet;
        set<vector<int>> atlanticSet;

        vector<vector<int>> pacificVisited(rows, vector<int>(cols, 0));
        vector<vector<int>> atlanticVisited(rows, vector<int>(cols, 0));

        queue<vector<int>> pacificQueue;
        queue<vector<int>> atlanticQueue;


        // Add Pacific Nodes
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 || j == 0){
                    pacificQueue.push({i, j});
                    pacificVisited[i][j] = 1;
                }
            }
        }

        // Add Atlantic Nodes
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == rows - 1 || j == cols -1){
                    atlanticQueue.push({i, j});
                    atlanticVisited[i][j] = 1;
                }
            }
        }

        // BFS
        pacificSet = bfs(heights, pacificVisited, pacificQueue);
        atlanticSet = bfs(heights, atlanticVisited, atlanticQueue);

        vector<vector<int>> result;
        for(auto cell : pacificSet){
            if(atlanticSet.count(cell)){
                result.push_back(cell);
            }
        }
        
        return result;
    }
};
