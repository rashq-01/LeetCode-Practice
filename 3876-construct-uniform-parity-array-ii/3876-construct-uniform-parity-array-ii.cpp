class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int MIN = *min_element(nums1.begin(),nums1.end());

        if(MIN%2 == 0){
            for(auto& num : nums1)if(num%2==1)return false;
        }

        return true;
    }
};