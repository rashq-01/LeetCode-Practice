class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int ans = INT_MAX;

        unordered_map<int,int> mp;

        int currSum = 0;
        for(int i=n-1;i>=0;i--){
            currSum += nums[i];
            if(currSum==x){
                ans = min(ans , n-i);
            }

            mp[currSum] = i;
        }

        currSum = 0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            if(currSum == x){
                ans = min(ans , i+1);
            }
            if(mp.count(x - currSum) && mp[x - currSum]>i){
                ans = min(ans , i+1 + n - mp[x - currSum]);
            }
        }

        return ans==INT_MAX ? -1 : ans;
        
    }
};