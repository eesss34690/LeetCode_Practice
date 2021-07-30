class Solution {
public:
 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int x=a+dx[i];
                    int y=b+dy[i];
                    if(isvalid(x,y,n,m)&&dp[x][y]>dp[a][b]+1){
                        q.push({x,y});
                        dp[x][y]=dp[a][b]+1;
                    }
                }
            }
        }
        return dp;
    }
    bool isvalid(int x,int y,int n,int m){
        if(x>=0&&y>=0&&x<n&&y<m)return true;
        return false;
    }
};
