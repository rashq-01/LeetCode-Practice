class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int curr = 0;
        for(auto& ch : s){
            if(ch=='(')curr++;
            if(ch==')')curr--;
            ans = max(ans , curr);
        }

        return ans;
    }
};