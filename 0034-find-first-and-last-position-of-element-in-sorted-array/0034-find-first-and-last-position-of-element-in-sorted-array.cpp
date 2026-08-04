class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int first = -1;
        int last = -1;
        while(left<=right){

            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                first = mid;
                right = mid-1;
            }
            else if(target<nums[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        left = 0;
        right = nums.size()-1;
        while(left<=right){

            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                last = mid;
                left = mid+1;
            }
            else if(target<nums[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return {first,last};
    }
};