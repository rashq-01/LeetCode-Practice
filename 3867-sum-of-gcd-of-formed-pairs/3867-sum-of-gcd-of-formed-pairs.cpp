class Solution {
public:
    int gcd(int a, int b){
        if(b==0)return a;

        return gcd(b,a%b);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd(n,0);
        int mxi = INT_MIN;
        for(int i=0;i<n;i++){
            mxi = max(mxi,nums[i]);
            prefixGcd[i] = gcd(nums[i],mxi);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int start = 0;
        int end = n-1;

        long long ans = 0;

        while(start<end){
            ans+=gcd(prefixGcd[start],prefixGcd[end]);

            start++;
            end--;
        }

        return ans;
    }
};