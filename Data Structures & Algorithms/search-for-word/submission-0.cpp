class Solution {
public:
    bool dfs(vector<vector<char>>& board,string &word,int index,int i,int j,int n,int m,vector<vector<bool>> &vis){
        if(index==word.size()){
            return true;
        }
        if(i<0 || i>=n || j<0 ||j>=m || vis[i][j] || board[i][j]!=word[index]){
            return false;
        }
        vis[i][j]=true;
        bool found = dfs(board,word,index+1,i+1,j,n,m,vis) || dfs(board,word,index+1,i-1,j,n,m,vis) || dfs(board,word,index+1,i,j+1,n,m,vis) || dfs(board,word,index+1,i,j-1,n,m,vis);
        vis[i][j]=false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,0,i,j,n,m,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};