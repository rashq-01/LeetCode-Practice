class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size()<26)return false;
        vector<bool> mp(26,false);
        for(auto& ch:sentence){
            mp[ch-'a']=true;
        }
        for(auto b:mp) if(!b)return false;
        return true;
    }
};