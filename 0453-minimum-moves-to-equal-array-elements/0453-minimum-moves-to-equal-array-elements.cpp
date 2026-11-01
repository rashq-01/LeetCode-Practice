class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int MIN = nums[0];
        for(int i=1;i<n;i++)MIN = min(MIN,nums[i]);

        int ans = 0;
        for(auto& num : nums){
            ans += (num - MIN);
        }

        return ans;
    }
};