class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid){
        if(i>=grid.size() || i<0)return ;
        if(j>=grid[0].size() || j<0)return ;
        if(grid[i][j] == '0') return;

        grid[i][j] = '0';
        dfs(i-1,j,grid);//Up
        dfs(i+1,j,grid);//Down
        dfs(i,j+1,grid);//Right
        dfs(i,j-1,grid);//Left
    }
    int numIslands(vector<vector<char>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int count = 0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '1'){
                count++;
                dfs(i,j,grid);
            }
        }
       }

       return count;
    }
};