class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int idx = 'z' - ch + 1;
            ans += (idx*(i+1));

        }
        return ans;
    }
};