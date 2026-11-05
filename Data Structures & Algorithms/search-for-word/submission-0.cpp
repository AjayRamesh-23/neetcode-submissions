class Solution {
public:
    bool dfs(int r, int c, int idx, string& word, vector<vector<char>>& board, vector<vector<int>>& visited){
        visited[r][c] = 1;
        if(word.size() == idx) return true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size()) continue;
            if(!visited[nr][nc] && board[nr][nc] == word[idx]){
                if(dfs(nr, nc, idx+1, word, board, visited)) return true;
            }
        }
        visited[r][c] = 0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i, j, 1, word, board, visited)) return true;
                }
            }
        }    
        return false;    
    }
};

