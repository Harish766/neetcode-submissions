class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &visited,int src){
        visited[src]=true;
        for(int v:adj[src]){
            if(!visited[v]){
                dfs(adj,visited,v);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u= edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        vector<int> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(adj,visited,i);
            }
        }
        return count;
    }
};
