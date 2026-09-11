class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj (n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        q.push({0,{src,0}});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int stop = curr.first;
            int node = curr.second.first;
            int wei = curr.second.second;

            if(stop>k){
                continue;
            }
            for(auto edge : adj[node]){
                int nei =edge.first;
                int ws =edge.second;
                if(ws + wei < dist[nei]){
                    dist[nei]=ws + wei;
                    q.push({stop+1,{nei,dist[nei]}});
                }
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};
