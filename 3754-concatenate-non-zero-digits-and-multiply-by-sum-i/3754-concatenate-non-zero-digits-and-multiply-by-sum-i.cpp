class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;

        long long x = 0;
        while(n){
            if(n%10 != 0) x = (x*10) + (n%10);
            n/=10;
        }
        long long rev = 0;
        long long org = x;
        long long sum = 0;
        while(x){
            int dig = x % 10;
            rev = rev*10 + dig;
            sum+=dig;

            x/=10;
        }

        return sum*rev;

    }
};