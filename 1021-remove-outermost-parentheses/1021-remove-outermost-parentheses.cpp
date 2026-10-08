class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";

        int start = 0;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                count++;
            }
            else{
                count--;
            }

            if((count==1 && s[i] == '(') || (count == 0 && s[i]==')'))continue;

            ans.push_back(s[i]);
        }

        return ans;
    }
};