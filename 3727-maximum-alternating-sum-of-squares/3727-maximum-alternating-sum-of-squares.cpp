class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        
        long long totalSquaredSum = 0;
        for(auto& num : nums){
            totalSquaredSum += (num * num);
        }

        long long ans = 0;
        int half = (n + 2 - 1) / 2;

        int left = 0;
        int right = nums.size()-1;
        while(half>0){
            long long leftMost = (long long)nums[left] * nums[left];
            long long rightMost = (long long)nums[right] * nums[right];
            if(leftMost > rightMost){
                ans += leftMost;
                left++;
            }
            else{
                ans += rightMost;
                right--;
            }
            cout<<half<<endl;
            half--;
        }

        return ((2 * ans) - totalSquaredSum);
    }
};