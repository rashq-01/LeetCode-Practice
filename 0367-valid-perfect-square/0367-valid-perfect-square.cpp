class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)return true;

        long long  start = 1;
        long long end = num/2;

        while(start<=end){
            long long mid = end + (start-end)/2;
            
            long long square = mid*mid;
            if(square == (long long)num){
                return true;
            }
            else if(mid*mid > num){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return false;
    }
};