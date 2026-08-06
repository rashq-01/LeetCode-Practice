class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        string ans = "";
        for(int k=0;k<n;k++){
            int i=k;
            int j=k;
            int start;
            int end;
            int maxLen = 0;
            while(i>=0 && j<n && s[i]==s[j]){
                if(j-i+1 >maxLen){
                    start = i;
                    end = j;
                    maxLen = j-i+1;
                }
                i--;
                j++;
            }


            i = k;
            j = k+1;
            while(i>=0 && j<n && s[i]==s[j]){
                if(j-i+1>maxLen){
                    start = i;
                    end = j;
                    maxLen = j-i+1;
                }
                i--;
                j++;
            }
            if(maxLen > ans.size()){
                ans = s.substr(start,maxLen);
            }
        }

        return ans;
    }
};