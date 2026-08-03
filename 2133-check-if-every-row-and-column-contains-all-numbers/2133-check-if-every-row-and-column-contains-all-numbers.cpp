class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int idx = abs(matrix[i][j]) -1;
                if(matrix[i][idx] < 0)return false;
                matrix[i][idx] *= (-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int idx = abs(matrix[j][i]) -1;
                if(matrix[idx][i] > 0)return false;
                matrix[idx][i] *= (-1);
            }
        }
        return true;
        
    }
};