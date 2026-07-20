class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = INT_MAX;
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]) < dist){
                ans = nums[i];
                dist = abs(nums[i]);
            }
            else if(abs(nums[i])==dist && nums[i]>ans){
                ans = nums[i];
            }
        }

        return ans;
    }
};