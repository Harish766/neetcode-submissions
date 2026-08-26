class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                q.push({{i,j},0});
            }
        }
        int dr[]={0,1,0,-1};
        int dc[]={-1,0,1,0};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
             for(int i=0;i<4;i++){
                int row=r+dr[i];
                int col=c+dc[i];
             if(row<n && col<m && row>=0 && col>=0 && grid[row][col]==2147483647){
                    grid[row][col]=dist+1;
                    q.push({{row,col},dist+1});
                }
             }
        }
        
    }
};
