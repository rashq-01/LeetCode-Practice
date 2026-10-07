class Solution {
public:
    int maxSize = -1;
    void solve(int i, int start, int end , string& s, string& curr,set<string>& ans){
        if(end>start)return;
        if(i>=s.size()){
            if(start==end){
                int temp = curr.size();
                maxSize = max(maxSize , temp);
                ans.insert(curr);
            }
            return;
        }
        if(s[i] == '('){
            solve(i+1,start,end,s,curr,ans);
            curr.push_back('(');
            solve(i+1,start+1,end,s,curr,ans);
            curr.pop_back();
        }
        else if(s[i] == ')'){
            solve(i+1,start,end,s,curr,ans);
            if(end<start){
                curr.push_back(')');
                solve(i+1,start,end+1,s,curr,ans);
                curr.pop_back();
            }
        }
        else{
            curr.push_back(s[i]);
            solve(i+1,start,end,s,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        string curr = "";
        solve(0,0,0,s,curr,ans);


        vector<string> a;
        for(auto el : ans){
            int temp = el.size();
            if(temp == maxSize)a.push_back(el);
        }
        return a;
    }
};