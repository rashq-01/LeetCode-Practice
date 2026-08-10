class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for(int i=n/2;i>=1;i--){
            if(n%i==0){
                string sub = s.substr(0,i);
                string newString = "";

                int times = n/i;
                while(times--){
                    newString += sub;
                }

                if(s==newString)return true;
            }
        }

        return false;
    }
};