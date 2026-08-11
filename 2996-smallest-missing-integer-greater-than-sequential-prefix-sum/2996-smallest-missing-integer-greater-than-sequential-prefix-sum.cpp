class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int total = nums[0];
        vector<int> mp(50,-1);
        for(auto& num : nums)mp[num-1] = 1;
        for(int j=1;j<n;j++){
            if(nums[j] == nums[j-1]+1){
                total+=nums[j];
            }
            else{
                break;
            }
        }
        while(total<=50 && mp[total-1]==1)total+=1;


        return total;

    }
};