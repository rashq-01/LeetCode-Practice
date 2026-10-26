class Solution {
public:
    void markWater(int i, int j, vector<vector<int>>& grid,long long& val){
        if(i>=grid.size() || i<0 || j >= grid[0].size() || j<0)return;
        if(grid[i][j] == 0)return;

        val += grid[i][j];

        grid[i][j] = 0;

        markWater(i+1,j,grid,val);
        markWater(i-1,j,grid,val);
        markWater(i,j+1,grid,val);
        markWater(i,j-1,grid,val);

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        
        int ans = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] != 0){
                    long long val = 0;
                    markWater(i,j,grid,val);

                    if(val % k == 0)ans++;
                }
            }
        }

        return ans;
    }
};