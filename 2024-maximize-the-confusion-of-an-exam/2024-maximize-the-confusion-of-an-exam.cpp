class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = -1;
        int wr = 0;
        while(j<n){
            while(j<n && wr<k){
                if(s[j] == 'F')wr++;
                j++;
            }
            while(j < n && s[j] == 'T'){
                j++;

            }
            ans = max(j-i,ans);

            if(s[i]=='F')wr--;

            i++;
        }

        i = 0;
        j = 0;
        wr = 0;
        while(j<n){
            while(j<n && wr<k){
                if(s[j] == 'T')wr++;
                j++;
            }
            while(j < n && s[j] == 'F'){
                j++;

            }
            ans = max(j-i,ans);

            if(s[i]=='T')wr--;

            i++;
        }

        return ans;
    }
};