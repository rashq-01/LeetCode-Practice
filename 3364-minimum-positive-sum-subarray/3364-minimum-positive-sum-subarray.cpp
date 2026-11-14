class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        vector<int> prefix(nums.size()+1);
        partial_sum(nums.begin() , nums.end() , prefix.begin() + 1);
        
        for(int k=l;k<=r;++k){
            for(int i=0;i+k<=nums.size();++i){
                int s  = prefix[i + k] - prefix[i];
                if(s > 0) ans = min(ans , s);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};