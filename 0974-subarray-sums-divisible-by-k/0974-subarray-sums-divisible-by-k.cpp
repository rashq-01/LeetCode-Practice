class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int mod = 0;
            if(prefixSum<0){
                mod = prefixSum % k;

                if(mod < 0){
                    mod +=k;
                }
            }
            else{
                mod = prefixSum % k;
            }
            if(mp.count(mod))ans+=mp[mod];

            mp[mod]++;


        }

        return ans;
    }
};