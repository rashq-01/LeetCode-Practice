class Solution {
public:
    int getProd(int x){
        int prod = 1;
        while(x){
            prod *= x%10;
            x/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;;i++){
            if(getProd(i) %t == 0)return i;
        }

        return 0;
    }
};