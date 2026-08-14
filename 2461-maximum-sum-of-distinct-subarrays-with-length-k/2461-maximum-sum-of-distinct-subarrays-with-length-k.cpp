class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = 0;
        long long currSum = 0;
        unordered_map<int,int> mp;

        for(int left=0,right=0;right<nums.size();right++){
            while(mp.count(nums[right])){
                mp.erase(nums[left]);
                currSum-=nums[left++];
            }


           mp[nums[right]]++;
            currSum += nums[right];

            if(right-left+1 == k){
                ans = max(ans,currSum);
                currSum-=nums[left];
                mp.erase(nums[left++]);
            }
        }


        return ans;
        
    }
};