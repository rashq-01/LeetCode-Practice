class Solution {
public:
    long long getAliceMax(int i,bool isAliceTurn,vector<int>& arr,vector<vector<long long>>& dp){
        if(i>=arr.size())return 0;

        if(dp[i][isAliceTurn] != LLONG_MIN)return dp[i][isAliceTurn];

        long long res = LLONG_MIN;

        if(isAliceTurn){
            if(i+2<arr.size()){
                res = max(res,arr[i]+arr[i+1]+arr[i+2]+getAliceMax(i+3,false,arr,dp));
                res = max(res,arr[i] + arr[i+1] + getAliceMax(i+2,false,arr,dp));
                res = max(res,arr[i] + getAliceMax(i+1,false,arr,dp));
            }
            
            else if(i+1<arr.size()){
                res = max(res,arr[i] + arr[i+1] + getAliceMax(i+2,false,arr,dp));
                res = max(res,arr[i] + getAliceMax(i+1,false,arr,dp));
            }
            else{
                res = max(res,arr[i] + getAliceMax(i+1,false,arr,dp));
            }

            dp[i][isAliceTurn] = res;
            return res;
        }

        res = LLONG_MAX;

        if(i+2<arr.size()){
            res = min(res,getAliceMax(i+3,true,arr,dp));
            res = min(res,getAliceMax(i+2,true,arr,dp));
            res = min(res,getAliceMax(i+1,true,arr,dp));
        }
        else if(i+1<arr.size()){
            res = min(res,getAliceMax(i+2,true,arr,dp));
            res = min(res,getAliceMax(i+1,true,arr,dp));
        }
        else{
            res = min(res,getAliceMax(i+1,true,arr,dp));
        }

        dp[i][isAliceTurn] = res;
        return res;

        
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<vector<long long>> dp(n,vector<long long>(2,LLONG_MIN));

        long long totalSum = accumulate(stoneValue.begin(),stoneValue.end(),0LL);

        long long AliceTotal = getAliceMax(0,true,stoneValue,dp);

        if(AliceTotal >(totalSum-AliceTotal)){
            return "Alice";
        }
        if(AliceTotal == (totalSum-AliceTotal)){
            return "Tie";
        }


        return "Bob";
    }
};