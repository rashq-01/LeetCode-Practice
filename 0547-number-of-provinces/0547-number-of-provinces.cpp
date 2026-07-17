class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& isConnected,int n){
        isConnected[i][j] = 0;

        for(int v = 0;v<n;v++){
            if(v==j)isConnected[j][v] = 0;
            if(isConnected[j][v])dfs(j,v,isConnected,n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();

        int ans = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    ans++;
                    dfs(i,j,isConnected,n);
                }
            }
        }

        return ans;
    }
};