class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //{{r,c},t}
        queue<pair<pair<int,int>,int>>rotten;
        int visited[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    rotten.push({{i,j},0});
                    visited[i][j]=2;
                }
                else
                    visited[i][j]=0;
            }
        }
        
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        
        int tm=0;
        while(!rotten.empty()){
            int r=rotten.front().first.first;
            int c=rotten.front().first.second;
            int t=rotten.front().second;
            tm=max(tm,t);
            rotten.pop();
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]==0 && grid[nr][nc]==1){//check the bound of the grid
                    rotten.push({{nr,nc},t+1});
                    visited[nr][nc]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=2 && grid[i][j]==1)
                return -1;
            }
        }
        return tm;
    }
};