class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum)return "";

        string ans = "";

        while(num){
            int dig = min(9,sum);
            sum -= dig;
            ans.push_back('0' + dig);
            num--;
        }

        return ans;
        
    }
};