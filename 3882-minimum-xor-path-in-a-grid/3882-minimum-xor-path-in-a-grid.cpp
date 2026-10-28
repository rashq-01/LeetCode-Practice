class Solution {
public:
    vector<vector<vector<int>>> dp;
    int m,n;
    int solve(int i, int j, int val, vector<vector<int>>& grid){
        if(i>=m || j>=n)return INT_MAX;
        
        val ^= grid[i][j];

        if(i==m-1 && j==n-1)return val;

        if(dp[i][j][val] != -1)return dp[i][j][val];

        int right = solve(i,j+1,val,grid);
        int down = solve(i+1,j,val,grid);

        return dp[i][j][val] = min(right,down);
        
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m , vector<vector<int>>(n , vector<int>(1024 , -1)));

        return solve(0,0,0,grid);
    }
};