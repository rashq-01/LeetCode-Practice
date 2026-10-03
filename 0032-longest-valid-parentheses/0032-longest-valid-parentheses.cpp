class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        
        int ans = 0;

        int left = 0;
        int right = 0;

        for(auto& ch : s){
            if(ch == '('){
                left++;
            }
            else{
                right++;
            }

            if(left == right){
                ans = max(ans , 2*right);
            }
            if(right>left){
                left = right = 0;
            }
        }

        left = right = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '('){
                left++;
            }
            else{
                right++;
            }

            if(left == right){
                ans = max(ans , 2*right);
            }
            if(left>right)left=right=0;
        }
        return ans;
    }
};