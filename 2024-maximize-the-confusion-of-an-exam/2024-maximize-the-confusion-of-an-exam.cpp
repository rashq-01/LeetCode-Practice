class Solution {
public:
    int solve(string s,int k,char ch){
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = -1;
        int wr = 0;
        char rv = ch=='T'?'F':'T';

        while(j<n){
            while(j<n && wr<k){
                if(s[j] == ch)wr++;
                j++;
            }

            while(j<n && s[j]==rv){
                j++;
            }
            ans=max(j-i,ans);
            if(s[i]==ch)wr--;

            i++;
        }

        return ans;
    }
    int maxConsecutiveAnswers(string s, int k) {
        return max(solve(s,k,'T'),solve(s,k,'F'));
    }
};