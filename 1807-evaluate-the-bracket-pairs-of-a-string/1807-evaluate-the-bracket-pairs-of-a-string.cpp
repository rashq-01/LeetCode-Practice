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

            int braceStart = i+1;
            while(i<s.size() && s[i] != ')'){
                i++;
            }
            int braceEnd = i-1;
            string key = s.substr(braceStart , braceEnd-braceStart+1);
            if(mp.count(key)){
                ans += mp[key];
            }
            else{
                ans.push_back('?');
            }
            
        }

        return ans;
    }
};