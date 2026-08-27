class Solution {
public:
    bool solve(int i,string& curr,vector<int>& freq,string& target,bool isGreater,string& res){
        if(i==target.size()){
            if(isGreater){
                res = curr;
                return true;
            }
            return false;
        }

        for(int ch='a'; ch<='z';ch++){
            if(freq[ch-'a'] == 0)continue;
            if(!isGreater && ch<target[i])continue;

            curr.push_back(ch);
            freq[ch-'a']--;
            if(!isGreater && ch>target[i])isGreater=true;
            if(solve(i+1,curr,freq,target,isGreater,res)){
                return true;
            }
            curr.pop_back();
            freq[ch-'a']++;
        }

        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        string curr = "";
        string res = "";
        vector<int> freq(26,0);
        for(auto& ch : s)freq[ch-'a']++;

        if(solve(0,curr,freq,target,false,res))return res;

        return "";
    }
};