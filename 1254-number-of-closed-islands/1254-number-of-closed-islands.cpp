class Solution {
public:
    int m,n;
    bool isClosed(int i, int j, vector<vector<int>>& grid){
        if(i>=m || i<0 || j>=n || j<0)return false;

        if(grid[i][j])return true;

        grid[i][j] = 1;

        return (isClosed(i+1,j,grid) &
                isClosed(i-1,j,grid) &
                isClosed(i,j+1,grid) &
                isClosed(i,j-1,grid));

    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    count += isClosed(i,j,grid);
                }
            }
        }
        

        return count;
    }
};