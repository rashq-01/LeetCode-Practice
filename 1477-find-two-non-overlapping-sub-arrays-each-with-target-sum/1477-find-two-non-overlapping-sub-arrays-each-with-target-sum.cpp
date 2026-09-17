class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int i = 0;
        int j = 0;

        int currSum = 0;

        vector<int> minTillIdx(n , INT_MAX);

        int bestMinLen = INT_MAX;
        int result = INT_MAX;

        while(j < n){
            currSum += arr[j];
            while(i < j && currSum>target){
                currSum -= arr[i++];
            }
            if(currSum == target){
                int len = j - i +1;

                if(i>0 && minTillIdx[i-1] != INT_MAX){
                    result = min(result,len + minTillIdx[i-1]);
                }
                bestMinLen = min(bestMinLen , len);

            }

            minTillIdx[j] = bestMinLen;
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};