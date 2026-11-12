class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        queue<pair<int, int>> q;
        int count = 1;
        q.push({0, -1});
        vector<int> visited(n, 0);
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            visited[node] = 1;
            q.pop();
            for(auto it: adjList[node]){
                if(!visited[it]){
                    q.push({it, node});
                    count++;
                    visited[it] = 1;
                }
                else if(it != parent){
                    return false;
                }
            }
        }
        return count == n;
    }
};
