class Solution {
public:
    int solve(int i,int j,vector<int>& pre,vector<vector<int>>& dp){
        if(i>=j)return 0;
        if(dp[i][j] != INT_MIN)return dp[i][j];
        int score = INT_MIN;
        for(int k=i;k<j;k++){
            int leftSum = pre[k] - (i-1>=0 ? pre[i-1] : 0);
            int rightSum = pre[j] - pre[k];
            if(leftSum > rightSum){
                score = max(score,rightSum + solve(k+1,j,pre,dp));
            }
            else if(rightSum>leftSum){
                score = max(score,leftSum + solve(i,k,pre,dp));
            }
            else{
                score = max(score,leftSum + solve(i,k,pre,dp));
                score = max(score,rightSum + solve(k+1,j,pre,dp));
            }
        }
        dp[i][j] = score;
        return score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if(n==1)return 0;

        vector<int> prefixSum(n,0);
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));

        prefixSum[0] = stoneValue[0];
        for(int i=1;i<n;i++)prefixSum[i] = prefixSum[i-1]+stoneValue[i];

        return solve(0,n-1,prefixSum,dp);
    }
};