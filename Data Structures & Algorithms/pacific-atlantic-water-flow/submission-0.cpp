class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;
        
        // Separate visited matrices for Pacific and Atlantic
        vector<vector<bool>> pacificVis(n, vector<bool>(m, false));
        vector<vector<bool>> atlanticVis(n, vector<bool>(m, false));
        
        // 1. Fill boundaries for Pacific (Top and Left)
        for (int i = 0; i < n; i++) {
            pacificQueue.push({i, 0});      // Left wall
            pacificVis[i][0] = true;
        }
        for (int j = 0; j < m; j++) {
            pacificQueue.push({0, j});      // Top wall
            pacificVis[0][j] = true;
        }
        
        // 2. Fill boundaries for Atlantic (Bottom and Right)
        for (int i = 0; i < n; i++) {
            atlanticQueue.push({i, m - 1}); // Right wall
            atlanticVis[i][m - 1] = true;
        }
        for (int j = 0; j < m; j++) {
            atlanticQueue.push({n - 1, j}); // Bottom wall
            atlanticVis[n - 1][j] = true;
        }
        
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        
        // Pacific Queue BFS Loop
        while(!pacificQueue.empty()){
                int r = pacificQueue.front().first;
                int c = pacificQueue.front().second;
                pacificQueue.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !pacificVis[nr][nc] && heights[nr][nc]>=heights[r][c]){
                        pacificVis[nr][nc] = true; // Mark as visited
                        pacificQueue.push({nr,nc});
                    }
                }
        }
        
        // Atlantic Queue BFS Loop
        while(!atlanticQueue.empty()){
                int r = atlanticQueue.front().first;
                int c = atlanticQueue.front().second;
                atlanticQueue.pop();
                for (int i = 0; i < 4; i++) {
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];
                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && !atlanticVis[nr][nc] && heights[nr][nc]>=heights[r][c]){
                        atlanticVis[nr][nc] = true; // Mark as visited
                        atlanticQueue.push({nr,nc});
                    }
                }
        }
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacificVis[i][j] && atlanticVis[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
    return result;

    }
};