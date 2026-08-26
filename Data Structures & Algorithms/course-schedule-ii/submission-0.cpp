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
    void check(int curr,vector<vector<int>> &adj,vector<bool> &visited,stack<int> &st){
        visited[curr]=true;
        for(int v:adj[curr]){
            if(!visited[v]){
                check(v,adj,visited,st);
            }
        }
        st.push(curr);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        for(auto edge:prerequisites){
            int course=edge[0];
            int prereq=edge[1];
            adj[prereq].push_back(course);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> visPath(numCourses,false);
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visPath,visited)){
                    return ans;
                }
            }
        }
        fill(visited.begin(), visited.end(), false); 
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                check(i,adj,visited,st);
            }
        }
        for(int i=0;i<numCourses;i++){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
