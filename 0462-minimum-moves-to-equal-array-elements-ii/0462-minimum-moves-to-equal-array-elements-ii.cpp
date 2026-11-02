class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() == 1)return 0;

        int n = nums.size();

        sort(nums.begin() , nums.end());

        int avg = nums[n/2];
        if(n % 2 == 0){
            avg = (nums[n/2 -1] + nums[n/2]) / 2;
        }

        int ans = 0;
        for(auto& num : nums)ans += abs(avg - num);

        return ans;
    }
};