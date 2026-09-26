class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string , string> mp;

        for(auto& val : knowledge){
            mp[val[0]] = val[1];
        }

        string ans = "";
        for(int i=0;i<s.size();i++){

            if(s[i]>='a' && s[i]<='z'){
                ans.push_back(s[i]);
                continue;
            }

            int start = i+1;
            while(i<s.size() && s[i] != ')'){
                i++;
            }

            int end = i-1;

            string key = s.substr(start , end-start+1);

            ans += mp.count(key) ? mp[key] : "?";
            
        }

        return ans;
    }
};