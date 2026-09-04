class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffix(n);
        suffix[n-1] = nums.back();

        for(int i=n-2;i>=0;i--){
            suffix[i] = min(nums[i],suffix[i+1]);
        }

        int ans = -1;
        int currMax = INT_MIN;
        
        for(int i=0;i<n;i++){
            currMax = max(currMax,nums[i]);
            int currScore = currMax - suffix[i];
            if(currScore<=k){
                return i;
            }

        }

        return -1;
    }
};