class Solution {
public:
    int m , n;
    vector<vector<vector<int>>> dp;
    bool solve(int i, int j ,int openCount , vector<vector<char>>& grid){
        
        openCount += (grid[i][j] == '(' ? 1 : -1);
        if(openCount<0)return false;

        if(dp[i][j][openCount] != -1)return dp[i][j][openCount];


        if(i==m-1 && j==n-1){
            dp[i][j][openCount] = openCount==0;
            return dp[i][j][openCount];
        }

        if(i+1<m && solve(i+1,j,openCount,grid))return dp[i][j][openCount]=true;
        if(j+1<n && solve(i,j+1,openCount,grid))return dp[i][j][openCount]=true;

        return dp[i][j][openCount]=false;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(m+n,-1)));

        if((m+n-1) % 2 == 1)return false;

        return solve(0,0,0,grid);
    }
};