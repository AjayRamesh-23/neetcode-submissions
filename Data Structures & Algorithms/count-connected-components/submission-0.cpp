class Solution {
public:

    void dfs(int edge, vector<vector<int>>& adjList, vector<int>& visited){
        visited[edge] = 1;
        for(auto it: adjList[edge]){
            if(!visited[it]){
                dfs(it, adjList, visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        int connected = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                connected+=1;
                dfs(i, adjList, visited);
            }
        }
        return connected;
    }
};
