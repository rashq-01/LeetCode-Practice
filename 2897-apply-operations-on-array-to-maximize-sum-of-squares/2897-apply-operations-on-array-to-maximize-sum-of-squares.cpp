class Solution {
public:
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> bits(32,0);
        for(int i=0;i<n;i++){
            int num = nums[i];

            int idx = 0;
            while(num){
                int bit = num & 1;
                if(bit){
                    bits[idx]++;
                }
                idx++;
                num>>=1;
            }
        }
        long long ans = 0;
        for(int i=0;i<k;i++){
            int num = 0;
            for(int j=31;j>=0;j--){
                int bit = 0;
                if(bits[j] > 0){
                    bit = 1;
                    bits[j]--;
                }
                num = num << 1;
                num = num | bit;
            }
            if(num<=0)break;

            long long square = (long long)num * num;
            ans = (ans + square) % MOD;
        }

        return ans;

    }
};