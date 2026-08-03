class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int col = n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((i==j || j==col)){
                    if(grid[i][j]==0)return false;
                }
                else if(grid[i][j]!=0)return false;
            }
            col--;
        }

        return true;
        
    }
};