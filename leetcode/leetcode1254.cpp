Number of Closed Islands

class Solution {
public:
    
    bool isSafe(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
    if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==0)
      return true;
        return false;
    }
    
    void solve(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=1;
        if(isSafe(i+1,j,grid))
            solve(i+1,j,grid);
        if(isSafe(i-1,j,grid))
            solve(i-1,j,grid);
        if(isSafe(i,j+1,grid))
            solve(i,j+1,grid);
        if(isSafe(i,j-1,grid))
            solve(i,j-1,grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)
                solve(i,0,grid);
            if(grid[i][m-1]==0)
                solve(i,m-1,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0)
                solve(0,i,grid);
            if(grid[n-1][i]==0)
                solve(n-1,i,grid);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                    solve(i,j,grid);
                }
            }
        }
        return count;
    }
};
