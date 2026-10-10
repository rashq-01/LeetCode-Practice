class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        long long k = (long long)k1 + k2;

        vector<int> diff(n);

        int mx = 0;
        long long total = 0;

        for(int i=0;i<n;i++){
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx,diff[i]);
            total += diff[i];
        }

        if(total<=k)return 0;

        int low = 0, high = mx;

        while(low < high){
            int mid = low + (high-low)/2;
            long long need = 0;

            for(int d : diff){
                if(d>mid)need += (d-mid);
            }

            if(need<=k){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }

        long long need = 0;
        long long ans = 0;

        for(int d : diff){
            if(d>low){
                need += (d-low);
                ans += (1LL * low * low);
            }
            else{
                ans += (1LL * d * d);
            }
        }

        long long rem = k - need;
        for(int d : diff){
            if(rem==0)break;

            if(d>=low && d>0){
                ans -= (2LL * low -1);
                rem--;
            }
        }

        return ans;

    }
};