class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> preSum(n,0);
        preSum[0] = stones[0];
        for(int i=1;i<stones.size();i++){
            preSum[i] += (preSum[i-1]+stones[i]);
        }

        vector<int> t(n,0);
        t[n-1] = preSum[n-1];

        for(int i=n-2;i>=1;i--){
            int take = preSum[i] - t[i+1];
            int skip = t[i+1];

            t[i] = max(take,skip);
        }

        return t[1];

    }
};