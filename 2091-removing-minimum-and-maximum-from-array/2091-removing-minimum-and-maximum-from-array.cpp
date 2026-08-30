class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxEl = nums[0];
        int minEl = nums[0];
        for(int k=1;k<nums.size();k++){
            if(nums[k] > maxEl){
                maxEl = nums[k];
                i = k;
            }
            if(nums[k] < minEl){
                minEl = nums[k];
                j = k;
            }
        }
        if(i==j){
            return min(i+1,n-i);
        }

        int ans = INT_MAX;
        if(i<j){
            swap(i,j);
        }
        ans = min(ans,j+1 + n - i);
        ans = min(ans,i+1);
        ans = min(ans,n-j);
        return ans;
        
    }
};