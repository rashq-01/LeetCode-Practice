class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = 0;
        long long currSum = 0;
        unordered_set<int> st;

        for(int left=0,right=0;right<nums.size();right++){
            while(st.count(nums[right])){
                st.erase(nums[left]);
                currSum-=nums[left++];
            }


            st.insert(nums[right]);
            currSum += nums[right];

            if(right-left+1 == k){
                ans = max(ans,currSum);
                currSum-=nums[left];
                st.erase(nums[left++]);
            }
        }


        return ans;
        
    }
};