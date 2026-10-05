class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int score = 0;
        for(auto& ch : s){
            if(ch == '('){
                score++;
            }
            else{
                score--;
                if(*(&ch - 1) == '(') ans += (1<<score);
            }
        }

        return ans;
    }
};