Number of Enclaves

class Solution {
public:
    
    bool isSafe(int i,int j,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1)
            return true;
        return false;
    }
    void solve(int x,int y,vector<vector<int>>& grid){
        grid[x][y]=0;
        
       if(isSafe(x+1,y,grid))
           solve(x+1,y,grid);
        
        if(isSafe(x-1,y,grid))
           solve(x-1,y,grid);
        
        if(isSafe(x,y+1,grid))
           solve(x,y+1,grid);
        
        if(isSafe(x,y-1,grid))
           solve(x,y-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)
                solve(i,0,grid);
            if(grid[i][m-1]==1)
                solve(i,m-1,grid);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)
                solve(0,i,grid);
            if(grid[n-1][i]==1)
                solve(n-1,i,grid);
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
    }
};
