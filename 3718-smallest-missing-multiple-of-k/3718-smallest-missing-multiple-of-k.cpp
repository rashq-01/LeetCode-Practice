class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int next = k;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==next){
                next = next + k;
            }
            else if(nums[i]>next)return next;
        }

        return next;
    }
};