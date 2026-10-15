class Solution {
public:
    bool isValid(int i, string& s, int j, string& p){
        if(i<0 && j<0)return true;

        if(j<0)return false;

        if(p[j] == '*'){
            if(j==0)return false;

            char ch = p[j - 1];

            if(isValid(i,s,j-2,p))return true;

            if(i>=0 && (s[i] == ch || ch == '.')){
                if(isValid(i-1,s,j,p))return true;
            }

            return false;
        }

        if(i>=0 && (p[j] == '.' || s[i] == p[j])){
            return isValid(i-1,s,j-1,p);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return isValid(s.size()-1,s,p.size()-1,p);
    }
};