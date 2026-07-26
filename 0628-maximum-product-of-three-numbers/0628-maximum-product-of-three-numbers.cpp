class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(auto& num : nums){
            if(num>=max1){
                if(max1>=max2){
                    if(max2>max3){
                        max3 = max2;
                    }
                    max2 = max1;
                }
                max1 = num;
            }
            else if(num>=max2){
                if(max2>max3){
                    max3 = max2;
                }
                max2 = num;
            }
            else if(num>max3){
                max3 = num;
            }

            if(num<=min1){
                if(min2>=min1)min2 = min1;
                min1 = num;
            }
            else if(num<min2){
                min2 = num;
            }
        }
        long long ans1 = 1;
        if(min1!=INT_MAX && min2!=INT_MAX){
            ans1 = (long long)min1 * min2;
        }
        long long ans = (long long)max1 * max2 * max3 > ans1*max1 ? (long long)max1 * max2 * max3 : ans1*max1;
        return ans;
    }
};