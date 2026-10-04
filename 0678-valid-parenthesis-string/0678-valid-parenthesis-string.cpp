class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int star = 0;
        int start = 0;
        int end = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                start++;
            }
            else if(s[i] == ')'){
                end++;
            }
            else{
                star++;
            }

            if(start+star < end)return false;
        }

        star = 0;
        start = 0;
        end = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '('){
                start++;
            }
            else if(s[i] == ')'){
                end++;
            }
            else{
                star++;
            }

            if(end+star < start)return false;
        }

        return true;
    }
};