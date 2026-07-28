class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()<=1)return s;
        string ans = "";
        if(s.size()%2 == 0){
            string firstHalf = s.substr(0,s.size()/2);
            sort(firstHalf.begin(),firstHalf.end());
            string secondHalf = firstHalf;
            reverse(secondHalf.begin(),secondHalf.end());
            ans = firstHalf + secondHalf;
        }
        else{
            string firstHalf = s.substr(0,s.size()/2);
            sort(firstHalf.begin(),firstHalf.end());
            string secondHalf = firstHalf;
            reverse(secondHalf.begin(),secondHalf.end());
            ans = firstHalf + s[s.size()/2] + secondHalf;
        }

        return ans;
    }
};