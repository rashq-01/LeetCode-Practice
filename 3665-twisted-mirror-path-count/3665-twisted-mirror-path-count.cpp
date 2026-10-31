class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int i, int j, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp, int m, int n, int dir){
        if(i>=m || j>=n)return 0;

        if(i==m-1 && j==n-1)return 1;

        if(dp[i][j][dir] != -1)return dp[i][j][dir];

        if(grid[i][j] == 1){
            if(dir == 1){
                return solve(i+1,j,grid,dp,m,n,0);
            }
            else if(dir == 0){
                return solve(i,j+1,grid,dp,m,n,1);
            }
        }

        long long move = 0;

        if(j+1 < n && grid[i][j+1]==0){
            move += solve(i,j+1,grid,dp,m,n,1);
        }
        else if(j+1 < n && grid[i][j+1] == 1){
            move += solve(i,j+1,grid,dp,m,n,1);
        }

        if(i+1 < m && grid[i+1][j] == 0){
            move += solve(i+1,j,grid,dp,m,n,0);
        }
        else if(i+1 < m && grid[i+1][j] == 1){
            move += solve(i+1,j,grid,dp,m,n,0);
        }

        return dp[i][j][dir]=move%MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2 , -1)));

        return solve(0,0,grid,dp,m,n,0);
    }
};