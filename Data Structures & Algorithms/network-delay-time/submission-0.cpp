class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1); 
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n + 1, INT_MAX); 
        queue<pair<int,int>> q;
        q.push({k,0});
        dist[k] = 0;
        int max_time=0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int node = curr.first;
            int dit=curr.second;
            for(auto edge:adj[node]){
                int nei=edge.first;
                int sig=edge.second;
                if(dit + sig < dist[nei]){
                    dist[nei]=dit + sig;
                    q.push({nei,dist[nei]});
                }
            }
        }
        for(int i=1;i<n+1;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            max_time = max(max_time, dist[i]);
        }
        return max_time;
    }
};
