class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int normalMaxSum = INT_MIN;
        int normalMinSum = INT_MAX;
        int totalSum = 0;

        int currMinSum = 0;
        int currMaxSum = 0;

        for(auto& num : nums){
            currMaxSum = max(num,currMaxSum + num);
            currMinSum = min(num,currMinSum+num);

            normalMaxSum = max(normalMaxSum,currMaxSum);
            normalMinSum = min(normalMinSum,currMinSum);
            totalSum+=num;
        }

        if(normalMinSum == totalSum)return normalMaxSum;

        return max(normalMaxSum,totalSum-normalMinSum);
    }
};