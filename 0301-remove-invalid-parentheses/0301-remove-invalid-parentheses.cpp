class Solution {
public:
    int maxSize = -1;
    void solve(int i, int count , string& s, string& curr,set<string>& ans){

        if(count<0)return;

        if(i>=s.size()){
            if(count==0){
                int temp = curr.size();
                maxSize = max(maxSize , temp);
                if(temp==maxSize)ans.insert(curr);
            }
            return;
        }


        if(s[i] == '('){
            //Skip
            solve(i+1,count,s,curr,ans);

            //Take
            curr.push_back('(');
            solve(i+1,count+1,s,curr,ans);
            curr.pop_back();
        }
        else if(s[i] == ')'){
            //Skip
            solve(i+1,count,s,curr,ans);

            //Take
            curr.push_back(')');
            solve(i+1,count-1,s,curr,ans);
            curr.pop_back();
        }
        else{
            curr.push_back(s[i]);
            solve(i+1,count,s,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        string curr = "";
        solve(0,0,s,curr,ans);


        vector<string> a;
        for(auto el : ans){
            int temp = el.size();
            if(temp == maxSize)a.push_back(el);
        }
        return a;
    }
};