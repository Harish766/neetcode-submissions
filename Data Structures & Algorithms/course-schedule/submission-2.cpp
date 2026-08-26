class Solution {
public:
    bool dfs(int src,vector<vector<int>> &adj,vector<bool> &visPath,vector<bool> &visited){
        visited[src]=true;
        visPath[src]=true;
        for(int v:adj[src]){
            if(!visited[v]){
                if(dfs(v,adj,visPath,visited)){
                    return true;
                }
            }else if(visPath[v]){
                return true;
            }
        }
        visPath[src]=false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto edge:prerequisites){
            int course=edge[0];
            int prereq=edge[1];
            adj[prereq].push_back(course);
        }
        vector<bool> visPath(numCourses,false);
        vector<bool> visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visPath,visited)){
                    return false;
                }
            }
        }
        return true;
    }
};
