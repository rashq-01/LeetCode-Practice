class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int MIN = INT_MAX;
        int MAX = INT_MIN;
        for(auto& num : nums){
            MIN = min(MIN,num);
            MAX = max(MAX,num);
        }
        vector<int> arr(MAX-MIN+1,0);
        for(auto& num : nums){
            arr[num-MIN]++;
        }
        vector<int> ans;
        for(int i=0;i<MAX-MIN+1;i++){
            if(arr[i]==0)ans.push_back(MIN+i);
        }
        return ans;
    }
};