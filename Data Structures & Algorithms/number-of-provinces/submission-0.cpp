class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>> isConnected){
        visited[node] = 1;
        int nodes = isConnected[0].size();
        for(int i = 0; i < nodes; i++){
            if(isConnected[node][i] == 1 && !visited[i]){
                dfs(i, visited, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes = isConnected.size();
        vector<int> visited(nodes);
        int count = 0;
        for(int i = 0; i < nodes; i++){
            if(!visited[i]) {
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
    }
};