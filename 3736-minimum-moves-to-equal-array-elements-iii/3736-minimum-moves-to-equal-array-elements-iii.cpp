class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int MAX = *max_element(nums.begin() , nums.end());

        int ans = 0;

        for(auto& num : nums) ans += (MAX - num);

        return ans;
    }
};