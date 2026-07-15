class Solution {
public:
    int gcd(int a, int b){
        if(a<b)swap(a,b);
        int temp = a;
        a = a % b;
        if(a==0)return b;

        return gcd(temp,a);
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum = n*n;
        int evenSum = n*(n+1);

        return gcd(oddSum,evenSum);
    }
};