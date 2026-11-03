class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int count = 1;

        queue<pair<int, int>> q;
        int src = 0;
        vector<int> visited(n, 0);
        visited[src] = 1;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(!visited[it]){
                    q.push({it, node});
                    count++;
                    visited[it] = 1;
                }
                else if(parent != it){
                    return false;
                }
            }
        }
        return count == n;
    }
};
