class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        while(i<j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int j, string& s, int k,vector<vector<int>>& dp){
        if(i>=s.size() || j>=s.size())return 0;

        if(dp[i][j] != -1)return dp[i][j];

        if(isPalindrome(i,j,s)){
            int consider = 1 + solve(j+1,j+k,s,k,dp);
            int shrink = solve(i,j+1,s,k,dp);
            int skip = solve(i+1,j+1,s,k,dp);

            dp[i][j] = max(consider,max(shrink,skip));

            return dp[i][j];
        }

        int shrink = solve(i,j+1,s,k,dp);
        int skip = solve(i+1,j+1,s,k,dp);

        dp[i][j] = max(shrink,skip);

        return dp[i][j];
    }
    int maxPalindromes(string s, int k) {
        if(k==1)return s.size();
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return solve(0,k-1,s,k,dp);
    }
};