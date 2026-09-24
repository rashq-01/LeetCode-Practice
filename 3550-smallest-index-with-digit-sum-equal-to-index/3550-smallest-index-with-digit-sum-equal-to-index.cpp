class Solution {
public:
    int getVal(int n){
        int val = 0;
        while(n){
            val += (n%10);
            n/=10;
        }
        return val;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i == getVal(nums[i]))return i;
        }
        return -1;
    }
};