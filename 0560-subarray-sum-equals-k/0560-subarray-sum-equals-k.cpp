class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        int count = 0;
        int currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum += nums[i];
            if(mp.count(currSum-k)) count+=mp[currSum - k];
            mp[currSum]++;
        }
        return count;
    }
};