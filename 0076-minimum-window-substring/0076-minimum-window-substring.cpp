class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";

        unordered_map<char,int> need;
        int needCount = 0;
        for(auto& ch : t){
            if(!need.count(ch))needCount++;
            need[ch]++;
        }

        unordered_map<char,int> have;
        int haveCount = 0;

        int minLen = INT_MAX;
        int startIdx = -1;

        int low = 0;
        int high = 0;

        while(high<s.size()){
            char ch = s[high];
            have[ch]++;

            if(need.count(ch) && need[ch]==have[ch]){
                haveCount++;
            }

            while(needCount==haveCount){
               if(high-low+1<minLen){
                    minLen = min(minLen,high-low+1);
                    startIdx = low;
               } 

                if(need.count(s[low]) && need[s[low]]==have[s[low]]){
                    haveCount--;
                }
                have[s[low]]--;
                low++;
            }

            high++;
        }


        return minLen == INT_MAX ? "" : s.substr(startIdx,minLen);


    }
};