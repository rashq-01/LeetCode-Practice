class Solution {
public:
    int maxProduct(int n) {
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        while(n){
            int dig = n % 10;
            if(dig>mx1){
                if(mx1>=mx2)mx2 = mx1;
                mx1 = dig;
            }
            else if(dig>mx2){
                mx2 = dig;
            }
            n/=10;
        }

        return mx1*mx2;

    }
};