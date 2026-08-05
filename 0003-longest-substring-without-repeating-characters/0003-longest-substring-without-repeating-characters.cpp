class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int low = 0;
        int high = 0;
        unordered_map<char,bool> mp;
        while(high<s.size()){
            if(!mp.count(s[high])){
                mp[s[high]] = true;
                high++;
            }
            else{
                mp.erase(s[low++]);
            }
            ans = max(ans,high-low);
        }
        return ans;
    }
};