class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<char>>& board,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || board[i][j]=='X'){
            return ;
        }
        vis[i][j]=true;
        dfs(i+1,j,vis,board,n,m);
         dfs(i,j+1,vis,board,n,m);
          dfs(i,j-1,vis,board,n,m);
           dfs(i-1,j,vis,board,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                 dfs(0,i,vis,board,n,m);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                 dfs(i, m-1, vis, board, n, m);
            }
        }
        // 4. Bottommost row (Fix: bounds check columns up to m)
        for(int i = 0; i < m; i++){
            if(!vis[n-1][i] && board[n-1][i] == 'O'){
                 dfs(n-1, i, vis, board, n, m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
    }
};
