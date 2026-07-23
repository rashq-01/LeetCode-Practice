class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return n;
        int a = 0 ;
        while(n){
            a++;
            n>>=1;
        }
        return 1<<a;
    }
};