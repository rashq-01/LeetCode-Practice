class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> result(k,0);
        vector<long long> dp(k,0);

        for(auto num : nums){
            vector<long long> next(k,0);

            int r = num % k;
            next[r]++;
            for(int oldR=0;oldR<k;oldR++){
                if(dp[oldR] == 0)continue;

                int newR = (oldR * r) % k;
                next[newR] += dp[oldR];
            }

            for(int r=0;r<k;r++){
                result[r] += next[r];
            }
            dp = next;
        }

        return result;
    }
};