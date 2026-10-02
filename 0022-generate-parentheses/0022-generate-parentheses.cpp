class Solution {
public:
    void solve(string& curr , int start, int end, int n, vector<string>& ans){
        if(start == n && end == n){
            ans.push_back(curr);
            return;
        }
        if(start < n){
            curr.push_back('(');
            solve(curr,start+1,end,n,ans);
            curr.pop_back();
        }
        if(end<start){
            curr.push_back(')');
            solve(curr,start,end+1,n,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        solve(curr,0,0,n,ans);
        return ans;
    }
};