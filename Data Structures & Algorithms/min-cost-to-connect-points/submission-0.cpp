class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int x2 = points[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) 
                    continue;
                int x3 = points[j][0];
                int x4 = points[j][1];
                int dist = abs(x1 - x3) + abs(x2 - x4);              
                adj[i].push_back({j, dist});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> inMST(n, false);
        pq.push({0,0});
        int sum = 0;
        int edgesCount = 0;

        while (!pq.empty() && edgesCount < n) {
            auto [wt, node] = pq.top();
            pq.pop();
            if (inMST[node]) continue;
            inMST[node] = true;
            sum += wt;
            edgesCount++;
            for (auto edge : adj[node]) {
                int nei = edge.first;
                int edgeWt = edge.second;
                if (!inMST[nei]) {
                    pq.push({edgeWt, nei});
                }
            }
        }

        return sum;
    }
};
