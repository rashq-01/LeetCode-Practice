class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        int ans = 0;

        unordered_map<int,int> freq;
        int exceed = 0;
        int idx = 0;
        while(idx<n){
            if(freq.count(nums[idx]) && freq[nums[idx]]==k){
                break;
            }
            freq[nums[idx++]]++;
        }
        ans = idx;
        int prev = 0;

        while(idx<n){
            freq[nums[idx]]++;
            if(freq.count(nums[idx]) && freq[nums[idx]]>k)exceed++;

            while(exceed>0){
                if(freq[nums[prev]]>k)exceed--;
                freq[nums[prev]]--;

                prev++;
            }
            ans = max(ans,idx-prev+1);
            idx++;
        }

        return ans;
    }
};