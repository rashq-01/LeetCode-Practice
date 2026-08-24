class Solution {
public:
    int n;
    int solve(int i,vector<int>& preSum,vector<int>& dp){
        if(i==n-1)return preSum[i];

        if(dp[i] != INT_MIN)return dp[i];
        
        int take = preSum[i] - solve(i+1,preSum,dp);
        int skip = solve(i+1,preSum,dp);

        dp[i] = max(take,skip);
        return dp[i];
    }
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<int> preSum(n,0);
        preSum[0] = stones[0];
        for(int i=1;i<stones.size();i++){
            preSum[i] += (preSum[i-1]+stones[i]);
        }
        vector<int> dp(n,INT_MIN);

        return solve(1,preSum,dp);

    }
};