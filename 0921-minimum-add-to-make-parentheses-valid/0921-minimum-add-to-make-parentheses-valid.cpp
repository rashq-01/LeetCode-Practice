class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int count = 0;
        for(auto& ch : s){
            if(ch == '('){
                count++;
            }
            else{
                count--;
                if(count<0){
                    ans += abs(count);
                    count = 0;
                }
            }
        }
        return ans+count;
    }
};