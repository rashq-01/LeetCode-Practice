class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto ch : s){
            if(ch == '(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.size() == 0)return false;
                char t = st.top();
                if((t=='(' && ch!=')') || (t=='{' && ch!='}') || (t=='[' && ch!=']'))return false;

                st.pop();
            }
        }

        return st.empty();
    }

};