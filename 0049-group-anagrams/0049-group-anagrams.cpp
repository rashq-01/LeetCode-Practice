class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())return {{""}};

        unordered_map<string,vector<string>> mp;
        for(auto str : strs){
            string org = str;
            sort(str.begin(),str.end());
            mp[str].push_back(org);
        }
        vector<vector<string>> ans;
        for(auto el : mp){
            ans.push_back(el.second);
        }

        return ans;
    }
};