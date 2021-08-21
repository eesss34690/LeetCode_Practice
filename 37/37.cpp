class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool col[9][9], row[9][9], cell[3][3][9];
        memset(col, 0x00, sizeof col);
        memset(row, 0x00, sizeof row);
        memset(cell, 0x00, sizeof cell);
        
        for(int i=0; i<9; ++i)
            for(int j=0; j<9; ++j){
                if(board[i][j]!='.'){
                    int u=board[i][j]-'1';
                    row[i][u]=col[j][u]=cell[i/3][j/3][u]=true;
                }
            }
        
        function<bool(int, int)> dfs=[&](int x, int y){
            if(y==9) x++, y=0;
            if(x==9) return true;
            else if(board[x][y]=='.'){
                for(int i=0; i<9; ++i){
                    if(!row[x][i] && !col[y][i] && !cell[x/3][y/3][i]){
                        board[x][y]='1'+i;
                        row[x][i]=col[y][i]=cell[x/3][y/3][i]=true;
                        if(dfs(x, y+1)) return true;
                        else{
                            board[x][y]='.';
                            row[x][i]=col[y][i]=cell[x/3][y/3][i]=false;
                        }
                    }
                }
            }else return dfs(x, y+1);
            return false;
        };
        
        dfs(0, 0);
    }
};
