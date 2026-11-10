class Solution {
public:
    int solve(int i,vector<int>& costs,int n,vector<int>& dp){
        if(i>n)return INT_MAX;
        if(i==n)return 0;

        int ans = INT_MAX;
        for(int step=1;step<=3;step++){
            if(step+i<=n){
                int next = dp[i+step] != -1 ? dp[i+step] : solve(i+step,costs,n,dp);
                if(next!=INT_MAX){
                    ans = min(ans,costs[i+step] + (step*step) + next);
                }
            }
        }
        dp[i] = ans;
        return ans;
    }
    int climbStairs(int k, vector<int>& costs) {
        int n = costs.size()-1;
        vector<int> dp(costs.size(),-1);
        int ans = INT_MAX;
        for(int i=0;i<=min(2,n);i++){
            ans = min(ans,costs[i] + ((i+1)*(i+1))+solve(i,costs,n,dp));
        }

        return ans;
    }
};