class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum = 0;
        long long prod = 1;
        long long org = n;
        while(n){
            int dig = n % 10;
            n/=10;
            sum += dig;
            prod *= dig;
        }


        return !(org % (sum+prod));
    }
};