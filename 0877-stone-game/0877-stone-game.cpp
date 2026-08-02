class Solution {
public:
    int getMaxAlice(int i,int n,bool isAliceTurn,vector<int>& piles,vector<vector<vector<int>>>& dp){
        if(i>n)return 0;
        if(dp[i][n][isAliceTurn] != -1)return dp[i][n][isAliceTurn];

        int takeFirst,takeLast;
        if(isAliceTurn){
            takeFirst = piles[i] + getMaxAlice(i+1,n,false,piles,dp);
            takeLast = piles[n] + getMaxAlice(i,n-1,false,piles,dp);

            dp[i][n][isAliceTurn] = max(takeFirst,takeLast);

            return max(takeFirst,takeLast);
        }

        takeFirst = getMaxAlice(i+1,n,true,piles,dp);
        takeLast = getMaxAlice(i,n-1,true,piles,dp);

        dp[i][n][isAliceTurn] = max(takeFirst,takeLast);

        return min(takeFirst,takeLast);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        int totalSum = accumulate(piles.begin(),piles.end(),0);
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));

        int AliceTotal = getMaxAlice(0,n-1,true,piles,dp);

        if(2*AliceTotal >= totalSum)return true;


        return false;
    }
};