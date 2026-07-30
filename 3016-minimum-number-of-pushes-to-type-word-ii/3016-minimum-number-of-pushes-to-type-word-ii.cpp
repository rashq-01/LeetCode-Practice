class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);

        for(auto& ch : word){
            mp[ch - 'a']++;
        }

        sort(mp.begin(),mp.end(),greater<>());
        int count = 0;
        for(int i=0;i<8;i++){
            count+=mp[i];
        }
        for(int i=8;i<16;i++){
            count+=(mp[i]*2);
        }
        for(int i=16;i<24;i++){
            count+=(mp[i]*3);
        }
        for(int i=24;i<26;i++){
            count += (mp[i]*4);
        }

        return count;
    }
};